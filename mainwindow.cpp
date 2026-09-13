#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDate currentDate = QDate::currentDate();
    ui->date->setText("Date : " + currentDate.toString("dd-MM-yyyy"));
    connect(ui->FromDateEdit, &QDateEdit::dateChanged, this, &MainWindow::onDateFilterChanged);
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &MainWindow::onDateFilterChanged);
    QIcon logoIcon(":/resources/logo.svg");
    ui->logoLabel->setPixmap(logoIcon.pixmap(100, 44));
    ui->insertButton->setIcon(QIcon(":/resources/insert_icon.svg"));
    ui->insertButton->setIconSize(QSize(18, 18));

    ui->extractButton->setIcon(QIcon(":/resources/extract_icon.svg"));
    ui->extractButton->setIconSize(QSize(18, 18));

    QIcon recordsIcon(":/resources/records_icon.svg");
    ui->recordsIconLabel->setPixmap(recordsIcon.pixmap(100,75));
    ui->DataTable->setShowGrid(true);
    ui->DataTable->setGridStyle(Qt::SolidLine);
}

void MainWindow::on_insertButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Select Data File",
        "",
        "All Supported Files (*.db *.csv *.txt);;SQLite Database (*.db);;CSV Files (*.csv);;Text Files (*.txt)"
        );

    if (filePath.isEmpty())
        return;

    selectedFilePath = filePath;
    QString fileName = QFileInfo(filePath).fileName();
    ui->fileStatus->setText("File : " + fileName);
}

void MainWindow::on_extractButton_clicked()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please insert a file first.");
        return;
    }

    ui->DataTable->setRowCount(0);

    QString extension = QFileInfo(selectedFilePath).suffix().toLower();

    if (extension == "db") {
        extractFromDb();
    } else if (extension == "csv") {
        extractFromDelimitedFile(",");
    } else if (extension == "txt") {
        extractFromDelimitedFile("\t");
    } else {
        QMessageBox::warning(this, "Unsupported File", "File type not supported.");
        return;
    }

    ui->totalrecords->setText(QString::number(ui->DataTable->rowCount()));
}

void MainWindow::extractFromDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "extractConnection");
    db.setDatabaseName(selectedFilePath);

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT timestamp, op_id, valve_name, valve_value, sensor_name, sensor_value FROM logs")) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        db.close();
        QSqlDatabase::removeDatabase("extractConnection");
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->DataTable->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            ui->DataTable->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        colorValveValueItem(ui->DataTable->item(row, 3));
        row++;
    }

    db.close();
    QSqlDatabase::removeDatabase("extractConnection");
}

void MainWindow::extractFromDelimitedFile(const QString &delimiter)
{
    QFile file(selectedFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Could not open file.");
        return;
    }

    QTextStream in(&file);

    if (in.atEnd()) {
        file.close();
        return;
    }

    QString headerLine = in.readLine();
    QStringList headers = headerLine.split(delimiter);

    QStringList expectedColumns = {"timestamp", "op_id", "valve_name", "valve_value", "sensor_name", "sensor_value"};
    QVector<int> columnIndex(expectedColumns.size(), -1);

    for (int i = 0; i < headers.size(); ++i) {
        QString cleanHeader = headers.at(i).trimmed().toLower();
        int expectedPos = expectedColumns.indexOf(cleanHeader);
        if (expectedPos != -1) {
            columnIndex[expectedPos] = i;
        }
    }

    for (int i = 0; i < expectedColumns.size(); ++i) {
        if (columnIndex[i] == -1) {
            QMessageBox::warning(this, "Missing Column",
                                 "Could not find column: " + expectedColumns[i] + " in file header.");
            file.close();
            return;
        }
    }

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(delimiter);

        if (fields.size() < headers.size())
            continue;

        ui->DataTable->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            int sourceIndex = columnIndex[col];
            ui->DataTable->setItem(row, col, new QTableWidgetItem(fields.at(sourceIndex).trimmed()));
        }
        colorValveValueItem(ui->DataTable->item(row, 3));
        row++;
    }

    file.close();
}

void MainWindow::on_searchButton_clicked()
{
    QString valveFilter = ui->valveEdit->text().trimmed();
    QString sensorFilter = ui->sensorEdit->text().trimmed();
    QString searchFilter = ui->searchEdit->text().trimmed();
    QDate fromDate = ui->FromDateEdit->date();
    QDate toDate = ui->dateEdit->date();

     bool dateFilterActive = dateFilterTouched;
    bool valveFilterActive = !valveFilter.isEmpty();
    bool sensorFilterActive = !sensorFilter.isEmpty();
    bool searchFilterActive = !searchFilter.isEmpty();

    int rowCount = ui->DataTable->rowCount();
    int visibleCount = 0;

    for (int row = 0; row < rowCount; ++row) {
        bool matches = true;

        // Date range check (column 0 = TimeStamp)
        if (dateFilterActive) {
            QString timestampText = ui->DataTable->item(row, 0)->text();
            QDate rowDate = QDateTime::fromString(timestampText, "yyyy-MM-dd HH:mm:ss").date();
            if (!rowDate.isValid() || rowDate < fromDate || rowDate > toDate) {
                matches = false;
            }
        }

        // Valve name check (column 2 = Valves)
        if (matches && valveFilterActive) {
            QString valveText = ui->DataTable->item(row, 2)->text();
            if (!valveText.contains(valveFilter, Qt::CaseInsensitive)) {
                matches = false;
            }
        }

        // Sensor name check (column 4 = Sensors)
        if (matches && sensorFilterActive) {
            QString sensorText = ui->DataTable->item(row, 4)->text();
            if (!sensorText.contains(sensorFilter, Qt::CaseInsensitive)) {
                matches = false;
            }
        }

        // Global search check (all columns)
        if (matches && searchFilterActive) {
            bool searchMatches = false;
            for (int col = 0; col < ui->DataTable->columnCount(); ++col) {
                QTableWidgetItem *item = ui->DataTable->item(row, col);
                if (item && item->text().contains(searchFilter, Qt::CaseInsensitive)) {
                    searchMatches = true;
                    break;
                }
            }
            if (!searchMatches) {
                matches = false;
            }
        }

        ui->DataTable->setRowHidden(row, !matches);
        if (matches) visibleCount++;
    }

    ui->totalrecords->setText(QString::number(visibleCount));
}

void MainWindow::onDateFilterChanged()
{
    dateFilterTouched = true;
}

void MainWindow::on_clearFilterButton_clicked()
{
    ui->FromDateEdit->blockSignals(true);
    ui->dateEdit->blockSignals(true);
    ui->FromDateEdit->setDate(QDate(2000, 1, 1));
    ui->dateEdit->setDate(QDate(2000, 1, 1));
    ui->FromDateEdit->blockSignals(false);
    ui->dateEdit->blockSignals(false);

    dateFilterTouched = false;

    ui->valveEdit->clear();
    ui->sensorEdit->clear();
    ui->searchEdit->clear();

    int rowCount = ui->DataTable->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        ui->DataTable->setRowHidden(row, false);
    }

    ui->totalrecords->setText(QString::number(rowCount));
}

void MainWindow::on_csvButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export CSV",
        "",
        "CSV Files (*.csv)"
        );

    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Export Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);

    // Header row
    QStringList headers;
    for (int col = 0; col < ui->DataTable->columnCount(); ++col) {
        headers << ui->DataTable->horizontalHeaderItem(col)->text();
    }
    out << headers.join(",") << "\n";

    // Data rows (only visible/unfiltered rows)
    for (int row = 0; row < ui->DataTable->rowCount(); ++row) {
        if (ui->DataTable->isRowHidden(row))
            continue;

        QStringList rowData;
        for (int col = 0; col < ui->DataTable->columnCount(); ++col) {
            QTableWidgetItem *item = ui->DataTable->item(row, col);
            rowData << (item ? item->text() : "");
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export Complete", "CSV file exported successfully.");
}

void MainWindow::on_excelButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export Excel",
        "",
        "Excel Files (*.xls)"
        );

    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Export Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    out << "<html><head><meta charset='utf-8'></head><body>\n";
    out << "<table border='1'>\n";

    // Header row
    out << "<tr>";
    for (int col = 0; col < ui->DataTable->columnCount(); ++col) {
        out << "<th>" << ui->DataTable->horizontalHeaderItem(col)->text() << "</th>";
    }
    out << "</tr>\n";

    // Data rows (only visible/unfiltered rows)
    for (int row = 0; row < ui->DataTable->rowCount(); ++row) {
        if (ui->DataTable->isRowHidden(row))
            continue;

        out << "<tr>";
        for (int col = 0; col < ui->DataTable->columnCount(); ++col) {
            QTableWidgetItem *item = ui->DataTable->item(row, col);
            out << "<td>" << (item ? item->text() : "") << "</td>";
        }
        out << "</tr>\n";
    }

    out << "</table></body></html>";
    file.close();

    QMessageBox::information(this, "Export Complete", "Excel file exported successfully.");
}

void MainWindow::colorValveValueItem(QTableWidgetItem *item)
{
    if (!item)
        return;

    QString value = item->text().trimmed();

    if (value == "0") {
        item->setBackground(QColor("#f8d7da"));
        item->setForeground(QColor("#842029"));
    } else if (value == "1") {
        item->setBackground(QColor("#d1f2dc"));
        item->setForeground(QColor("#0f5132"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

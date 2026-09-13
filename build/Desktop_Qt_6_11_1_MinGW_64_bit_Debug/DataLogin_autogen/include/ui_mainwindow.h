/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *filterData;
    QLabel *sensorname;
    QLabel *ToDate;
    QLineEdit *sensorEdit;
    QLabel *valvename;
    QDateEdit *dateEdit;
    QLineEdit *valveEdit;
    QPushButton *searchButton;
    QLineEdit *searchEdit;
    QLabel *search;
    QDateEdit *FromDateEdit;
    QLabel *FromDate;
    QPushButton *clearFilterButton;
    QGroupBox *extractedData;
    QHBoxLayout *horizontalLayout;
    QTableWidget *DataTable;
    QGroupBox *fileInformation;
    QVBoxLayout *verticalLayout;
    QPushButton *insertButton;
    QLabel *fileStatus;
    QPushButton *extractButton;
    QGroupBox *records;
    QLabel *totalrecordhd;
    QLabel *totalrecords;
    QLabel *recordsIconLabel;
    QGroupBox *exportOption;
    QPushButton *csvButton;
    QPushButton *excelButton;
    QLabel *date;
    QLabel *logoLabel;
    QLabel *Title;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1293, 844);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        filterData = new QGroupBox(centralwidget);
        filterData->setObjectName("filterData");
        filterData->setGeometry(QRect(10, 380, 361, 291));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        filterData->setFont(font);
        sensorname = new QLabel(filterData);
        sensorname->setObjectName("sensorname");
        sensorname->setGeometry(QRect(184, 124, 128, 22));
        ToDate = new QLabel(filterData);
        ToDate->setObjectName("ToDate");
        ToDate->setGeometry(QRect(184, 34, 71, 22));
        sensorEdit = new QLineEdit(filterData);
        sensorEdit->setObjectName("sensorEdit");
        sensorEdit->setGeometry(QRect(190, 160, 165, 31));
        valvename = new QLabel(filterData);
        valvename->setObjectName("valvename");
        valvename->setGeometry(QRect(12, 124, 116, 22));
        dateEdit = new QDateEdit(filterData);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(180, 70, 161, 28));
        dateEdit->setCalendarPopup(true);
        valveEdit = new QLineEdit(filterData);
        valveEdit->setObjectName("valveEdit");
        valveEdit->setGeometry(QRect(0, 160, 165, 31));
        searchButton = new QPushButton(filterData);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(12, 248, 93, 31));
        searchEdit = new QLineEdit(filterData);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setGeometry(QRect(90, 210, 251, 31));
        search = new QLabel(filterData);
        search->setObjectName("search");
        search->setGeometry(QRect(12, 213, 63, 22));
        FromDateEdit = new QDateEdit(filterData);
        FromDateEdit->setObjectName("FromDateEdit");
        FromDateEdit->setGeometry(QRect(10, 70, 151, 28));
        FromDateEdit->setCalendarPopup(true);
        FromDate = new QLabel(filterData);
        FromDate->setObjectName("FromDate");
        FromDate->setGeometry(QRect(12, 34, 95, 22));
        clearFilterButton = new QPushButton(filterData);
        clearFilterButton->setObjectName("clearFilterButton");
        clearFilterButton->setGeometry(QRect(180, 250, 151, 31));
        extractedData = new QGroupBox(centralwidget);
        extractedData->setObjectName("extractedData");
        extractedData->setGeometry(QRect(410, 60, 871, 611));
        extractedData->setFont(font);
        horizontalLayout = new QHBoxLayout(extractedData);
        horizontalLayout->setObjectName("horizontalLayout");
        DataTable = new QTableWidget(extractedData);
        if (DataTable->columnCount() < 6)
            DataTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        DataTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        DataTable->setObjectName("DataTable");

        horizontalLayout->addWidget(DataTable);

        fileInformation = new QGroupBox(centralwidget);
        fileInformation->setObjectName("fileInformation");
        fileInformation->setGeometry(QRect(10, 65, 361, 141));
        fileInformation->setFont(font);
        verticalLayout = new QVBoxLayout(fileInformation);
        verticalLayout->setObjectName("verticalLayout");
        insertButton = new QPushButton(fileInformation);
        insertButton->setObjectName("insertButton");

        verticalLayout->addWidget(insertButton);

        fileStatus = new QLabel(fileInformation);
        fileStatus->setObjectName("fileStatus");

        verticalLayout->addWidget(fileStatus);

        extractButton = new QPushButton(fileInformation);
        extractButton->setObjectName("extractButton");

        verticalLayout->addWidget(extractButton);

        records = new QGroupBox(centralwidget);
        records->setObjectName("records");
        records->setGeometry(QRect(10, 220, 361, 151));
        records->setFont(font);
        totalrecordhd = new QLabel(records);
        totalrecordhd->setObjectName("totalrecordhd");
        totalrecordhd->setGeometry(QRect(18, 30, 331, 111));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        totalrecordhd->setFont(font1);
        totalrecordhd->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        totalrecords = new QLabel(records);
        totalrecords->setObjectName("totalrecords");
        totalrecords->setGeometry(QRect(52, 60, 291, 71));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        totalrecords->setFont(font2);
        totalrecords->setAlignment(Qt::AlignmentFlag::AlignCenter);
        recordsIconLabel = new QLabel(records);
        recordsIconLabel->setObjectName("recordsIconLabel");
        recordsIconLabel->setGeometry(QRect(20, 60, 151, 71));
        recordsIconLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        exportOption = new QGroupBox(centralwidget);
        exportOption->setObjectName("exportOption");
        exportOption->setGeometry(QRect(10, 680, 1271, 101));
        exportOption->setFont(font);
        csvButton = new QPushButton(exportOption);
        csvButton->setObjectName("csvButton");
        csvButton->setGeometry(QRect(70, 30, 281, 51));
        excelButton = new QPushButton(exportOption);
        excelButton->setObjectName("excelButton");
        excelButton->setGeometry(QRect(910, 30, 291, 51));
        date = new QLabel(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(1120, 30, 151, 21));
        date->setFont(font);
        date->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);
        logoLabel = new QLabel(centralwidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setGeometry(QRect(20, 10, 161, 44));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy);
        logoLabel->setMinimumSize(QSize(44, 44));
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(60, 10, 241, 51));
        Title->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1293, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        filterData->setTitle(QCoreApplication::translate("MainWindow", "FILTER DATA ", nullptr));
        sensorname->setText(QCoreApplication::translate("MainWindow", "Sensor _ Name :", nullptr));
        ToDate->setText(QCoreApplication::translate("MainWindow", "To Date :", nullptr));
        valvename->setText(QCoreApplication::translate("MainWindow", "Valve _ Name :", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "SEARCH ", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "Search :", nullptr));
        FromDate->setText(QCoreApplication::translate("MainWindow", "From Date :", nullptr));
        clearFilterButton->setText(QCoreApplication::translate("MainWindow", "CLEAR FILTERS", nullptr));
        extractedData->setTitle(QCoreApplication::translate("MainWindow", "EXTRACTED DATA ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = DataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "TimeStamp", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = DataTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Op_id", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = DataTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Valves ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = DataTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = DataTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Sensors", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = DataTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        fileInformation->setTitle(QCoreApplication::translate("MainWindow", "FILE INFORMATION ", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "INSERT FILE ", nullptr));
        fileStatus->setText(QCoreApplication::translate("MainWindow", "  File : No File Selected ", nullptr));
        extractButton->setText(QCoreApplication::translate("MainWindow", "EXTRACT DATA ", nullptr));
        records->setTitle(QCoreApplication::translate("MainWindow", "RECORDS ", nullptr));
        totalrecordhd->setText(QCoreApplication::translate("MainWindow", "TOTAL RECORDS ", nullptr));
        totalrecords->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        recordsIconLabel->setText(QString());
        exportOption->setTitle(QCoreApplication::translate("MainWindow", "EXPORT OPTIONS ", nullptr));
        csvButton->setText(QCoreApplication::translate("MainWindow", "CSV ", nullptr));
        excelButton->setText(QCoreApplication::translate("MainWindow", "EXCEL ", nullptr));
        date->setText(QCoreApplication::translate("MainWindow", "Date : 24-08-2026", nullptr));
        logoLabel->setText(QString());
        Title->setText(QCoreApplication::translate("MainWindow", "DataViewer Pro ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

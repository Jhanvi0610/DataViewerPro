#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/resources/style.qss");
    bool opened = styleFile.open(QFile::ReadOnly);
    qDebug() << "Style file opened:" << opened;

    QString styleSheet = QLatin1String(styleFile.readAll());
    qDebug() << "Style sheet length:" << styleSheet.length();

    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}
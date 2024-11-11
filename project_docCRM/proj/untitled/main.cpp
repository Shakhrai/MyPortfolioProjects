#include "mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile stylesheet (":/Diffnes.qss");
    stylesheet.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(stylesheet.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();
    return a.exec();
}

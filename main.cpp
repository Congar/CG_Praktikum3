//Version 1.0
//24.04.2017
#include "mainwindow.h"
#include <QApplication>

// main function
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

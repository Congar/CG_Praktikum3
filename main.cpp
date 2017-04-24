
//Version 1.0
//Aufgabe 3.2

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

//Version 1.0
//24.04.2017
#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
// main function
int main(int argc, char *argv[])
{

    QSurfaceFormat format;format.setVersion(4, 5); // requested OpenGL version; you might have to change this
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setOption(QSurfaceFormat::DeprecatedFunctions);
    format.setOption(QSurfaceFormat::DebugContext);
    QSurfaceFormat::setDefaultFormat(format);
    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    return a.exec();
}

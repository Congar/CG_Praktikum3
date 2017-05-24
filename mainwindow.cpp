#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Slider zu Spinbox
    /*connect(ui->sldRotationZ,SIGNAL(valueChanged(int)),
            ui->sbxRotationZ,SLOT(setValue(int)));
    //Slider für Rotation zu Fenster
    connect(ui->sldRotationZ,SIGNAL(valueChanged(int)),
            ui->widget, SLOT(receiveRotationZ(int)));
    //Slider zu Fenster für Zoom
    connect(ui->widget,SIGNAL(valueChanged(int)),
            ui->sbxZoom, SLOT(setValue(int)));
    ui->sbxZoom->setValue(-7);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    mInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mInit()
{
    baseWid* bw=new baseWid(ui->graphicsView);
    baseWid* bw2=new baseWid(ui->graphicsView,bw);
    baseWid* bw3=new baseWid(ui->graphicsView,bw);

    qDebug()<<bw->getSonsHeight()<<endl;
}

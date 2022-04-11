#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);
    ui->setupUi(this);

     connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
     ui->lcdNumberSec->setStyleSheet("background-color:black;");
     ui->lcdNumberMin->setStyleSheet("background-color:white;");
     connect(timer, &QTimer::timeout, this, &MainWindow::update);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (not(timer->isActive())){
        timer->start(100);
    }
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    ui->lcdNumberSec->display(nullptr);
    ui->lcdNumberMin->display(nullptr);
}

void MainWindow::update()
{
    ui->lcdNumberSec->display(ui->lcdNumberSec->value()+1);
    if (ui->lcdNumberSec->value() == 60){
        ui->lcdNumberMin->display(ui->lcdNumberMin->value()+1);
        ui->lcdNumberSec->display(0);
    }
}

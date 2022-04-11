#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecounter.hh"
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBoxN->setRange(0,1000);
    ui->spinBoxG->setRange(0,120);
    ui->spinBoxP->setRange(0,250);
    ui->spinBoxE->setRange(0,5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_countPushButton_clicked()
{
    unsigned int N = ui->spinBoxN->value();
    unsigned int G = ui->spinBoxG->value();
    unsigned int P = ui->spinBoxP->value();
    unsigned int E = ui->spinBoxE->value();
    unsigned int vastaus = count_final_grade(N,G,P,E);
    const QString v = QString::number(vastaus);
    const QString teksti = "Total grade: " + v;
    ui->textBrowser->setText(teksti);
    return;
}




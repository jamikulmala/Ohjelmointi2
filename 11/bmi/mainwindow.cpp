#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::countBMI(float kg, float cm)
{
    float m2 = pow(cm/100,2);
    float index = kg/m2;
    return index;
}

const QString MainWindow::returnmessage(float BMI)
{
    if(BMI < 18.5){
        return UNDERWEIGHT;
    }

    else if(BMI < 25){
        return NORMAL;
    }

    else if(BMI > 25){
        return OVERWEIGHT;
    }
    return NORMAL;
}

void MainWindow::on_countButton_clicked()
{
    QString pituus = ui->heightLineEdit->text();
    QString paino = ui->weightLineEdit->text();
    float cm = pituus.toFloat();
    float kg = paino.toFloat();

    if(cm == 0){
        ui->infoTextBrowser->setText("");
        ui->resultLabel->setText(CANNOT);
        return;
    }
    else{

    float BMI = countBMI(kg,cm);
    const QString v = QString::number(BMI);

    ui->infoTextBrowser->setText(returnmessage(BMI));
    ui->resultLabel->setText(v);
    }

}


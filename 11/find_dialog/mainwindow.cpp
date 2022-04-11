#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QFile>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findPushButton_clicked()
{
    if (QFile::exists(ui->fileLineEdit->text())){
        QFile file(ui->fileLineEdit->text());
        file.open(QIODevice::ReadWrite);
        if (ui->matchCheckBox->isChecked()){
            if(ui->keyLineEdit->text().isEmpty()){
               ui->textBrowser->setText(FILE_FOUND);
                }
            else{
                 QTextStream filetext(&file);
                 QString search(ui->keyLineEdit->text());
                 while(not filetext.atEnd()){
                       QString line = filetext.readLine();
                       if (line.contains(search, Qt::CaseSensitive)){
                           ui->textBrowser->setText(WORD_FOUND);
                       }
                  }
                 ui->textBrowser->setText(NOT_FOUND);
                }
            }
            else{
                if(ui->keyLineEdit->text().isEmpty()){
                    ui->textBrowser->setText(FILE_FOUND);
                }
                else{
                    QTextStream filetext(&file);
                    QString search(ui->keyLineEdit->text());
                    while(not filetext.atEnd()){
                          QString line = filetext.readLine();
                          if (line.contains(search, Qt::CaseInsensitive)){
                              ui->textBrowser->setText(WORD_FOUND);
                         }
                   }
                ui->textBrowser->setText(NOT_FOUND);
                }
            }
        file.close();
        }

    else{
         ui->textBrowser->setText(FILE_NOT_FOUND);
        }
}


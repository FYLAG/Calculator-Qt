#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(eventClickNumber()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(eventClickNumber()));

}

void MainWindow::eventClickNumber() {

    static double result = 0;

    QPushButton *button = static_cast<QPushButton*>(sender());

    result = result * 10 + (button->text()).toDouble();

    QString resultStr = QString::number(result, 'g', 12);

    ui->label_result->setText(resultStr);

}

MainWindow::~MainWindow() {

    delete ui;

}


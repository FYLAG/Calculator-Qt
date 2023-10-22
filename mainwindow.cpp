#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    this->valueFirst = 0;
    this->valueSecond = 0;

    this->valueLink = &valueFirst;
    this->operationStr = "";

    this->function = nullptr;

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

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(eventClickNumberDot()));

    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(eventClearOutput()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(eventClickSum()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(eventClickSubtract()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(eventClickMultiply()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(eventClickDivision()));

    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(eventClickPercent()));
    connect(ui->pushButton_sign, SIGNAL(clicked()), this, SLOT(eventClickSignReverse()));

    connect(ui->pushButton_result, SIGNAL(clicked()), this, SLOT(eventClickResult()));

}

double MainWindow::functionSum(double a, double b) {

    double result = a + b;

    return result;

}

double MainWindow::functionSubtract(double a, double b) {

    double result = a - b;

    return result;

}

double MainWindow::functionMultiply(double a, double b) {

    double result = a * b;

    return result;

}

double MainWindow::functionDivision(double a, double b) {

    double result = a / b;

    return result;

}

void MainWindow::functionPercent(double *val) {

    if (*val != 0.0f) {
        *val /= 100;
    }

    if (this->function == &MainWindow::functionSum ||
        this->function == &MainWindow::functionDivision) {

        *val *= this->valueFirst;

    }

}

void MainWindow::functionSignReverse(double *val) {

    if (*val != 0.0f) {
        *val *= -1;
    }

}

void MainWindow::setOutputValue(double value) {

    QString resultStr = QString::number(value, 'g', 12);

    ui->label_result->setText(resultStr);

}

void MainWindow::clearData() {

    valueLink = &valueFirst;

    valueFirst = 0;
    valueSecond = 0;

    operationStr = "";

    function = nullptr;

}

void MainWindow::eventClearOutput() {

    clearData();

    ui->label_operation->setText("");
    ui->label_result->setText("0");

}

void MainWindow::eventClickNumber() {

    QPushButton *button = static_cast<QPushButton*>(sender());

    *valueLink = *valueLink * 10 + (button->text()).toDouble();

    setOutputValue(*valueLink);

}

void MainWindow::eventClickNumberDot() {



}

void MainWindow::eventClickSum() {

    this->function = &MainWindow::functionSum;
    this->valueLink = &valueSecond;

    this->operationStr = QString::number(valueFirst, 'g', 8) + " + ";

    ui->label_operation->setText(this->operationStr);

    *this->valueLink = 0;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickSubtract() {

    this->function = &MainWindow::functionSubtract;
    this->valueLink = &valueSecond;

    this->operationStr = QString::number(valueFirst, 'g', 8) + " - ";

    ui->label_operation->setText(this->operationStr);

    *this->valueLink = 0;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickMultiply() {

    this->function = &MainWindow::functionMultiply;
    this->valueLink = &valueSecond;

    this->operationStr = QString::number(valueFirst, 'g', 8) + " * ";

    ui->label_operation->setText(this->operationStr);

    *this->valueLink = 0;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickDivision() {

    this->function = &MainWindow::functionDivision;
    this->valueLink = &valueSecond;

    this->operationStr = QString::number(valueFirst, 'g', 8) + " / ";

    ui->label_operation->setText(this->operationStr);

    *this->valueLink = 0;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickPercent() {

    functionPercent(this->valueLink);
    setOutputValue(*this->valueLink);

}

void MainWindow::eventClickSignReverse() {

    functionSignReverse(this->valueLink);
    setOutputValue(*this->valueLink);

}

void MainWindow::eventClickResult() {

    if (this->function != nullptr) {

        double result = (this->*function)(this->valueFirst, this->valueSecond);

        this->operationStr += QString::number(this->valueSecond, 'g', 8) + " = ";

        ui->label_operation->setText(this->operationStr);

        this->valueFirst = result;

        setOutputValue(result);

    }

}

MainWindow::~MainWindow() {

    delete ui;

}
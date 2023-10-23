#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    valueFirst = 0;
    valueSecond = 0;

    decimal = 1;

    valueLink = &valueFirst;
    operationStr = "";

    function = nullptr;

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

    if (function == &MainWindow::functionSum ||
        function == &MainWindow::functionDivision) {

        *val *= valueFirst;

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

void MainWindow::addCharOutput(char character) {

    QString outputStr = ui->label_result->text() + character;

    ui->label_result->setText(outputStr);

}

void MainWindow::clearData() {

    valueLink = &valueFirst;

    valueFirst = 0;
    valueSecond = 0;

    decimal = 1;

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

    if (decimal < 1) {

        *valueLink = *valueLink + (button->text()).toDouble() * decimal;

        decimal /= 10;

    } else {

        *valueLink = *valueLink * 10 + (button->text()).toDouble();

    }

    setOutputValue(*valueLink);

}

void MainWindow::eventClickNumberDot() {

    decimal /= 10;
    addCharOutput('.');

}

void MainWindow::eventClickSum() {

    function = &MainWindow::functionSum;
    valueLink = &valueSecond;

    operationStr = QString::number(valueFirst, 'g', 8) + " + ";

    ui->label_operation->setText(operationStr);

    *valueLink = 0;
    decimal = 1;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickSubtract() {

    function = &MainWindow::functionSubtract;
    valueLink = &valueSecond;

    operationStr = QString::number(valueFirst, 'g', 8) + " - ";

    ui->label_operation->setText(operationStr);

    *valueLink = 0;
    decimal = 1;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickMultiply() {

    function = &MainWindow::functionMultiply;
    valueLink = &valueSecond;

    operationStr = QString::number(valueFirst, 'g', 8) + " * ";

    ui->label_operation->setText(operationStr);

    *valueLink = 0;
    decimal = 1;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickDivision() {

    function = &MainWindow::functionDivision;
    valueLink = &valueSecond;

    operationStr = QString::number(valueFirst, 'g', 8) + " / ";

    ui->label_operation->setText(operationStr);

    *valueLink = 0;
    decimal = 1;

    setOutputValue(valueSecond);

}

void MainWindow::eventClickPercent() {

    functionPercent(valueLink);
    setOutputValue(*valueLink);

}

void MainWindow::eventClickSignReverse() {

    functionSignReverse(valueLink);
    setOutputValue(*valueLink);

}

void MainWindow::eventClickResult() {

    if (function != nullptr) {

        double result = (this->*function)(valueFirst, valueSecond);

        operationStr += QString::number(valueSecond, 'g', 8) + " = ";

        ui->label_operation->setText(operationStr);

        valueFirst = result;

        setOutputValue(result);

    }

}

MainWindow::~MainWindow() {

    delete ui;

}
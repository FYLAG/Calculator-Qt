#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    double valueFirst;
    double valueSecond;

    double decimal;

    double *valueLink;

    QString operationStr;

    double (MainWindow::*function)(double, double);

    /* FUNCTIONS */

    double functionSum(double, double);
    double functionSubtract(double, double);
    double functionMultiply(double, double);
    double functionDivision(double, double);

    void functionPercent(double*);
    void functionSignReverse(double*);

    void setOutputValue(double);
    void addCharOutput(char);

    void clearData();

private slots:

    void eventClearOutput();
    void eventClickNumber();

    void eventClickNumberDot();

    void eventClickSum();
    void eventClickSubtract();
    void eventClickMultiply();
    void eventClickDivision();

    void eventClickPercent();

    void eventClickSignReverse();

    void eventClickResult();

};
#endif // MAINWINDOW_H

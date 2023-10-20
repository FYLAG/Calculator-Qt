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

    double *valueLink;

    QString *operationStr;

    double (MainWindow::*function)(double, double);

    /* FUNCTIONS */

    double functionSum(double, double);
    double functionSubtract(double, double);
    double functionMultiply(double, double);
    double functionDivision(double, double);

    void setOutputValue(double);

    void clearData();

private slots:

    void eventClearOutput();
    void eventClickNumber();

    void eventClickSum();
    void eventClickSubtract();
    void eventClickMultiply();
    void eventClickDivision();

    void eventClickResult();

};
#endif // MAINWINDOW_H

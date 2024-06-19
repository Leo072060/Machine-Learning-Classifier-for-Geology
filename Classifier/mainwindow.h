#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDir>
#include"trainwindow.h"
#include"predictwindow.h"
#include"evaluatewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    TrainWindow* m_TrainWindow;
    PredictWindow* m_PredictWindow;
    EvaluateWindow* m_EvaluateWindow;

    void OpenTrainWindow();
};
#endif // MAINWINDOW_H

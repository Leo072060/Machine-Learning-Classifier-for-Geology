#include "predictwindow.h"
#include "ui_predictwindow.h"

PredictWindow::PredictWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PredictWindow)
{
    ui->setupUi(this);
}

PredictWindow::~PredictWindow()
{
    delete ui;
}

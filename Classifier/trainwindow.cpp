#include "trainwindow.h"
#include "ui_trainwindow.h"

TrainWindow::TrainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrainWindow)
{
    ui->setupUi(this);

}

TrainWindow::~TrainWindow()
{
    delete ui;
}

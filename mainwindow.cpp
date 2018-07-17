#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QPicture>
// #include <QPixmap>

#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
:
QMainWindow(parent),
ui(new Ui::MainWindow)
// , background(":/bg.png") 
{
    ui->setupUi(this);
    // ui->MapLabel->setPixmap(background);
}

MainWindow::~MainWindow() {
    delete ui;
}

/* void MainWindow::resizeEvent(QResizeEvent* event) {
//    QPixmap *map = ui->MapLabel->pixmap();
    // update();
    // cout << "ama here" << endl;
    // QMainWindow::resizeEvent(event);
    // int w = ui->MapLabel->width();
    // int h = ui->MapLabel->height();
    // cout << "maplabel width = " << w << endl;
    // cout << "maplabel height = " << h << endl << endl;


    // w = this->width() - ;
    // h = this->height() - 20;
    // cout << "window width = " << w << endl;
    // cout << "window height = " << h << endl << endl;

    // ui->MapLabel->setBaseSize(QSize(w, h));

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    // ui->MapLabel->setPixmap(background.scaled(w,h,Qt::KeepAspectRatio));
    // Your code here.
} */

void MainWindow::on_pushButton_clicked() {

}

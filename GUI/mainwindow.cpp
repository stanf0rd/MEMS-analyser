#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QPicture>
// #include <QPixmap>

#include "configuration.h"
// TODO: clean up includes
#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
:
QMainWindow(parent),
ui(new Ui::MainWindow) {
    ui->setupUi(this);
    SetDefaultValues();
#ifdef _WIN32
    // fixing windows-style button bug
    ui->pushButton->setStyleSheet("margin: -1px;");
#endif
    // ui->MapLabel->setPixmap(background);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::GetChosenValues(
    ConderSizes &conderSizes,
    int &offset, int &topOffset,
    int &conderCount, int &vectorCount//,
    // int &graphicsAreaWidth, int &graphicsAreaHeight
) const {
    conderSizes.height = ui->conderHeightBox->value();
    conderSizes.width = ui->conderWidthBox->value();
    conderSizes.delta = ui->conderDeltaBox->value();
    offset = ui->offsetBox->value();
    topOffset = ui->topOffsetBox->value();
    conderCount = ui->conderCountBox->value();
    vectorCount = ui->vectorCountBox->value();
    // graphicsAreaWidth = ui->conderMapView->width();
    // graphicsAreaHeight = ui->conderMapView->height();
}

void MainWindow::on_pushButton_clicked() {
    Configuration::Instance().Update(*this);
    this->ui->conderMapView->GenerateScene();
    this->ui->conderMapView->DrawScene();
}

void MainWindow::SetDefaultValues() {
    // TODO: set capacitors position
    // TODO: set capacitors type
    auto const &config = Configuration::Instance();
    auto &gui = *(this->ui);
    gui.conderCountBox->setValue(config.getAskedConderCount());
    gui.vectorCountBox->setValue(config.getVectorCount());
    gui.topOffsetBox->setValue(config.getTopOffset());
    gui.offsetBox->setValue(config.getOffset());
    auto const &conderSizes = config.getConderSizes();
    gui.conderWidthBox->setValue(conderSizes.width);
    gui.conderHeightBox->setValue(conderSizes.height);
    gui.conderDeltaBox->setValue(conderSizes.delta);
}

/* void MainWindow::resizeEvent(QResizeEvent* event) {
//    QPixmap *map = ui->MapLabel->pixmap();
    // update();
    // cout << "ama here" << endl;
    QMainWindow::resizeEvent(event);
    int w = this->width();
    int h = this->height();
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

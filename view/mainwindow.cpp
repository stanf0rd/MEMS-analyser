#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "controller.hpp"
#include "configuration.hpp"
#include "config.hpp"


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

FieldWidget* MainWindow::getFieldWidget() {
    return ui->fieldWidget;
}


const Configuration MainWindow::GetCurrentConfig() const {
    const FieldSizes fieldSizes(
        // TODO: FIXME: check if this is right
        ui->fieldWidget->width(),
        ui->fieldWidget->height(),
        ui->offsetBox->value(),
        ui->topOffsetBox->value()
    );

    const ConderSizes conderSizes(
        ui->conderWidthBox->value(),
        ui->conderHeightBox->value(),
        ui->conderDeltaBox->value()
    );

    const Configuration config(
        fieldSizes,
        conderSizes,
        ui->vectorCountBox->value(),
        ui->conderCountBox->value()
    );

    return config;
}


void MainWindow::SetDefaultValues() {
    // TODO: set capacitors position
    // TODO: set capacitors type

    auto &gui = *(this->ui);

    const auto &config = defaultConfig;
    gui.conderCountBox->setValue(config.askedConderCount);
    gui.vectorCountBox->setValue(config.askedVectorCount);

    const auto &fieldSizes = config.fieldSizes;
    gui.topOffsetBox->setValue(fieldSizes.topOffset);
    gui.offsetBox->setValue(fieldSizes.offset);

    const auto &conderSizes = config.conderSizes;
    gui.conderWidthBox->setValue(conderSizes.width);
    gui.conderHeightBox->setValue(conderSizes.height);
    gui.conderDeltaBox->setValue(conderSizes.delta);
}

void MainWindow::on_pushButton_clicked() {
    auto &controller = Controller::Instance();
    controller.Generate(GetCurrentConfig());
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

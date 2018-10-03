/* by stanford */
#pragma once

#include <QMainWindow>
#include "configuration.hpp"
#include "conder.hpp"
#include "fieldwidget.hpp"


namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    FieldWidget* getFieldWidget();
    const Configuration GetCurrentConfig() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void SetDefaultValues();
    // QPixmap background;
    // void resizeEvent(QResizeEvent* event);
};

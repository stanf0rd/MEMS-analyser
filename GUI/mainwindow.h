#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conder.h"


namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void GetChosenValues(
        ConderSizes &conderSizes,
        int &offset, int &topOffset,
        int &conderCount, int &vectorCount//,
        // int &graphicsAreaWidth, int &graphicsAreaHeight
    ) const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void SetDefaultValues();
    // QPixmap background;
    // void resizeEvent(QResizeEvent* event);
};

#endif  // MAINWINDOW_H

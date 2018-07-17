/* by stanford */
#include "mainwindow.h"
#include <QApplication>

#include "conder_map.h"

const int topOffset = 20;  // in percent
const int offset = 10;     // in pixels

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

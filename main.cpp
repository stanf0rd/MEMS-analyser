/* by stanford */
#include <QApplication>
#include "controller.hpp"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Controller::Instance();

    return a.exec();
}

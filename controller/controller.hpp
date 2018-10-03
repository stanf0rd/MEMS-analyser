#include "configuration.hpp"
#include "model.hpp"
#include "mainwindow.hpp"


class Controller {
public:
    static Controller& Instance();
    bool Generate(Configuration);

private:
    Model model;
    MainWindow *const window;
    FieldWidget *const widget;

    Controller(const Configuration &);
    ~Controller() = default;

    // deny coping
    Controller(Controller const&) = delete;
    Controller& operator= (Controller const&) = delete;
};

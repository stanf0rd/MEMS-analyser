#include "controller.hpp"
#include "config.hpp"


Controller::Controller(const Configuration &config)
: model(config)
, window(new MainWindow)
, widget(window->getFieldWidget())
{
    window->show();
}


Controller& Controller::Instance() {
    static Controller instance(defaultConfig);
    return instance;
}

bool Controller::Generate(Configuration config) {
    if (config.isValid()) {
        model.SetConfig(config);
        model.GenerateScene();
        widget->DrawScene(model.getConders(), model.getVectors());
        // TODO: view: show generated stuff
        return true;
    } else {
        return false;
    }
}

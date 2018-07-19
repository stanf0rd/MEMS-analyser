/* by stanford */

#include "configuration.h"

Configuration::Configuration()
: conderSizes(defaultConderSizes)
, offset(defaultOffset)
, topOffset(defaultTopOffset)
{
    ReadConfigFile();
}

void Configuration::ReadConfigFile() {
    // TODO: write config file parser
}

Configuration& Configuration::Instance() {
    static Configuration c;
    c.Update();
    return c;
}

void Configuration::Update() {
    /* call mainwindow's method getInputValues or like that */
}

const int& Configuration::getOffset() const {
    return offset;
}

const int& Configuration::getTopOffset() const {
    return topOffset;
}

/* by stanford */

#include "configuration.h"

Configuration::Configuration()
: conderSizes(defaultConderSizes)
, offset(defaultOffset)
, topOffset(defaultTopOffset)
{
    ReadConfigFile();
    Update();  // set defaults to mainwindow boxes
}

void Configuration::ReadConfigFile() {
    // TODO: write config file parser
}

Configuration& Configuration::Instance() {
    static Configuration c;
    return c;
}

void Configuration::Update() {
    // TODO: /* call mainwindow's method getInputValues or like that */
}

const int& Configuration::getOffset() const {
    return offset;
}

const int& Configuration::getTopOffset() const {
    return topOffset;
}

const ConderSizes& Configuration::getConderSizes() const {
    return conderSizes;
}

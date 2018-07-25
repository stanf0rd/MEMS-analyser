/* by stanford */
#include "configuration.h"


Configuration::Configuration()
: conderSizes(defaultConderSizes)
, offset(defaultOffset)
, topOffset(defaultTopOffset)
, askedConderCount(defaultConderCount)
, vectorCount(defaultVectorCount)
{
    ReadConfigFile();
    // TODO: set defaults to mainwindow boxes
}

void Configuration::ReadConfigFile() {
    // TODO: write config file parser
}

Configuration& Configuration::Instance() {
    static Configuration c;
    return c;
}

void Configuration::Update(MainWindow const &window) {
    window.GetChosenValues(
        conderSizes, offset, topOffset,
        askedConderCount, vectorCount
    );
}

int Configuration::getOffset() const {
    return offset;
}

int Configuration::getTopOffset() const {
    return topOffset;
}

const ConderSizes& Configuration::getConderSizes() const {
    return conderSizes;
}

int Configuration::getAskedConderCount() const {
    return askedConderCount;
}

int Configuration::getVectorCount() const {
    return vectorCount;
}

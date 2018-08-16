/* by stanford */
#include "configuration.h"


Configuration::Configuration()
: conderSizes(defaultConderSizes)
, offset(defaultOffset)
, topOffset(defaultTopOffset)
, askedConderCount(defaultConderCount)
, askedVectorCount(defaultVectorCount)
{
    ReadConfigFile();
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
        askedConderCount, askedVectorCount//,
        // graphicsAreaWidth, graphicsAreaHeight
    );
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

const int& Configuration::getAskedConderCount() const {
    return askedConderCount;
}

const int& Configuration::getAskedVectorCount() const {
    return askedVectorCount;
}

// TODO: do we need this?
// const int& Configuration::getGraphicsAreaWidth() const {
//     return graphicsAreaWidth;
// }

// const int& Configuration::getGraphicsAreaHeight() const {
//     return graphicsAreaHeight;
// }

/* by stanford */
#pragma once

#include "config.h"
#include "conder.h"
#include "mainwindow.h"

class Configuration {
public:
    static Configuration& Instance();
    void Update(MainWindow const &window);
    const ConderSizes& getConderSizes() const;
    int getOffset() const;
    int getTopOffset() const;
    int getAskedConderCount() const;
    int getVectorCount() const;

    // void ReadFromUI();
private:
    ConderSizes conderSizes;

    int offset;
    int topOffset;
    int askedConderCount;
    int vectorCount;
    int graphicsAreaWidth = 0;
    int graphicsAreaHeight = 0;

    Configuration();
    ~Configuration() = default;
    void ReadConfigFile();

    // deny coping
    Configuration(Configuration const&) = delete;
    Configuration& operator= (Configuration const&) = delete;
};

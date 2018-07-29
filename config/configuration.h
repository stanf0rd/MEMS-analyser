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
    const int& getOffset() const;
    const int& getTopOffset() const;
    const int& getAskedConderCount() const;
    const int& getVectorCount() const;
    const int& getGraphicsAreaWidth() const;
    const int& getGraphicsAreaHeight() const;

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

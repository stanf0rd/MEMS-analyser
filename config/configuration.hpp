/* by stanford */
#pragma once

#include "conder.hpp"


struct FieldSizes {
    const int width;
    const int height;

    const int offset;
    const int topOffset;

    bool isValid() const;
    FieldSizes(int w, int h, int offset, int topOffset);
    FieldSizes(const FieldSizes &) = default;
    FieldSizes& operator=(const FieldSizes &);
};


struct Configuration {
    const FieldSizes fieldSizes;
    const ConderSizes conderSizes;

    const int askedConderCount;
    const int askedVectorCount;

    bool isValid() const;
    Configuration(FieldSizes, ConderSizes, int, int);
    Configuration(const Configuration &) = default;
    Configuration& operator=(const Configuration &);
};

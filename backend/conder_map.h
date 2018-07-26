#pragma once

#include "conder.h"
#include "matrix.hpp"

#include <vector>

using simple_matrix::Matrix;
using std::vector;

struct ConderMapSizes {
    int width;        // from GUI
    int height;       // from GUI
    int offset;       // from config
    int topOffset;    // from config
    ConderMapSizes(const int width, const int height);
};

class ConderMap {
public:
    ConderMap(const ConderMapSizes, const ConderSizes);
    // ~ConderMap();
    int GenConders(const int count);
    const vector<Conder>& getConders() const;
private:
    const ConderSizes conderSizes;
    const ConderMapSizes mapSizes;

    Matrix<bool> *map;

    int conderCount;
    // TODO: leftAngle, rightAngle
    vector<Conder> conders;
};

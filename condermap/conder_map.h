#pragma once

#include <vector>

#include "conder.h"
#include "matrix.hpp"

using simple_matrix::Matrix;


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
    ~ConderMap();

    void setVectorsBegin(const Dot dot);
    const Dot& getVectorsBegin() const;

    int GenConders(const int &count);
    void CountRanges();

    int GenVectors(const int &count);

    const std::vector<Conder>& getConders() const;
    const std::vector<Vector>& getVectors() const;

private:
    const ConderSizes conderSizes;
    const ConderMapSizes mapSizes;

    Matrix<bool> *map;

    int conderCount;
    int vectorCount;
    std::vector<Conder> conders;
    std::vector<Vector> vectors;
    Dot vectorsBegin;
};

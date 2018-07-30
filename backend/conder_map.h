#pragma once

#include <map>
#include <vector>

#include "conder.h"
#include "matrix.hpp"

using std::map;
using std::vector;
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
    int GenVectors(const int &Count);
    int GenConders(const int &count, vector<Conder> &generatedConders);
    void setVectorsBegin(const Dot dot);
    void VectorToMap(const std::vector<Conder>&);
    const Dot& getVectorsBegin() const;
    void CountRanges(vector<Conder> &generatedConders);
    const std::map<float, Conder>& getConders() const;
    const std::vector<Vector>& getVectors() const;
private:
    const ConderSizes conderSizes;
    const ConderMapSizes mapSizes;

    Matrix<bool> *map;

    int conderCount;
    std::map<float, Conder> conders;
    std::vector<Vector> vectors;
    Dot vectorsBegin;
};

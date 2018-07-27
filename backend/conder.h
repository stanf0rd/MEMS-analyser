#pragma once

#include <vector>
#include <utility>
#include "matrix.hpp"
#include "vector.h"

using simple_matrix::Dot;
typedef std::pair<Vector, Vector> VectorPair;


struct ConderSizes {
    int width;
    int height;
    int delta;
    ConderSizes(int w, int h, int d);
};

class Conder {
public:
    Conder(const Dot coord, const ConderSizes &sizes);
    // ~Conder();
    const Dot& getCoord() const;
    const ConderSizes& getSizes() const;
    void setVectorRange(Vector &left, Vector &right);
    const VectorPair& getVectorRange() const;
private:
    // range of vectors, which crosses conder
    const VectorPair *vectorRange;
    std::vector<Vector> crossings;
    Dot coord;  // left bottom dot
    const ConderSizes &sizes;
    void CountSideAngles();
};

#pragma once

#include "matrix.hpp"
using simple_matrix::Dot;

struct ConderSizes {
    int width;
    int height;
    int delta;
    ConderSizes(int w, int h, int d);
};

class Conder {
public:
    Conder(Dot _coord, ConderSizes *_sizes);
    // ~Conder();
    Dot getCoord() const;
    ConderSizes getSizes() const;
    void setSizes(ConderSizes);
private:
    Dot coord;
    ConderSizes *sizes;
    void CountSideAngles();
};

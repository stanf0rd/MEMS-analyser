#pragma once

#include "matrix.hpp"
using simple_matrix::Dot;

struct ConderSizes {
    int width;
    int height;
    int delta;
};

class Conder {
    public:
        Conder(Dot _coord, ConderSizes *_sizes) : coord(_coord), sizes(_sizes) {};
        ~Conder();
        Dot getCoord() const { return coord; };
        ConderSizes getSizes() const { return *sizes; };
        void setSizes(ConderSizes);
    private:
        Dot coord;
        ConderSizes *sizes;
};

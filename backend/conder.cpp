#include "conder.h"


ConderSizes::ConderSizes(int w, int h, int d)
:
width(w), height(h), delta(d) {}


Conder::Conder(Dot _coord, ConderSizes *_sizes)
:
coord(_coord), sizes(_sizes) {
    // CountSideAngles();
};

Dot Conder::getCoord() const {
    return coord;
}

ConderSizes Conder::getSizes() const {
    return *sizes;
}

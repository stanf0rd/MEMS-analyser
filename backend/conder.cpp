#include "conder.h"

ConderSizes::ConderSizes(int w, int h, int d)
:
width(w), height(h), delta(d) {}


Conder::Conder(const Dot _coord, const ConderSizes &_sizes)
:
coord(_coord), sizes(_sizes), vectorRange(nullptr) {
    crossings.resize(3);  // max crossings per conder
    // CountSideAngles();
};

const Dot& Conder::getCoord() const {
    return coord;
}

const ConderSizes& Conder::getSizes() const {
    return sizes;
}

void Conder::setVectorRange(Vector &left, Vector &right) {
    if (vectorRange) delete vectorRange;
    vectorRange = new VectorPair(left, right);
}

const VectorPair& Conder::getVectorRange() const {
    return *vectorRange;
}

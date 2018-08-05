#include "conder.h"

ConderSizes::ConderSizes(int w, int h, int d)
:
width(w), height(h), delta(d) {}


Conder::Conder(const Dot _coord, const ConderSizes &_sizes)
:
coord(_coord), sizes(_sizes) {}

// Conder::~Conder() {}

const Dot& Conder::getCoord() const {
    return coord;
}

const ConderSizes& Conder::getSizes() const {
    return sizes;
}

void Conder::setVectorRange(Vector left, Vector right) {
    vectorRange = std::make_pair(left, right);
}

const Vector& Conder::getLeftVector() const {
    return vectorRange.first;
}

const Vector& Conder::getRightVector() const {
    return vectorRange.second;
}

bool Conder::AddCrossing(const Vector * vector) {
    // std::cout << "crossings vector size = " << crossings.size() << endl;
    if (crossings.size() == 3) return false;
    crossings.push_back(vector);
    // std::cout << "crossings vector size = " << crossings.size() << endl;
    return true;
}

const std::vector<const Vector *>& Conder::getCrossings() const {
    return crossings;
}

#include <cassert>
#include "conder.h"


ConderSizes::ConderSizes(int w, int h, int d)
:
width(w), height(h), delta(d) {}


Conder::Conder(const Dot _coord, const ConderSizes &_sizes)
: coord(_coord)
, sizes(_sizes) {}


const Dot& Conder::getCoord() const {
    return coord;
}

const ConderSizes& Conder::getSizes() const {
    return sizes;
}


bool Conder::RangeIsSet() const {
    return vectorRange.has_value();
}

void Conder::CountVectorRange(const Dot &vectorsBegin) {
    const auto leftVectorEnd =
        (coord.x <= vectorsBegin.x) ?
        Dot(coord + Dot(0, sizes.height)) :
        Dot(coord);
    auto leftVector = Vector(vectorsBegin, leftVectorEnd);

    const auto rightVectorEnd =
        (coord.x + sizes.width <= vectorsBegin.x) ?
        Dot(coord + Dot(sizes.width, 0)) :
        Dot(coord + Dot(sizes.width, sizes.height));
    auto rightVector = Vector(vectorsBegin, rightVectorEnd);

    vectorRange.emplace(leftVector, rightVector);
}

const Vector& Conder::getLeftVector() const {
    return vectorRange->first;
}

const Vector& Conder::getRightVector() const {
    return vectorRange->second;
}


bool Conder::IsCrossed(const Vector &vector) const {
    assert(RangeIsSet());
}

bool Conder::AddCrossing(const Vector * vector) {
    if (crossings.size() == 3) return false;  // TODO: hardcode
    crossings.push_back(vector);
    return true;
}

const std::vector<const Vector *>& Conder::getCrossings() const {
    return crossings;
}

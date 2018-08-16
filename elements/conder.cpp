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
    assert(vector.getBegin() == vectorRange->first.getBegin());

    float leftAngle = vectorRange->first.getAngle();
    float rightAngle = vectorRange->second.getAngle();

    return leftAngle < vector.getAngle()
        && rightAngle > vector.getAngle();
}

void Conder::AddCrossing(const Vector * vector) {
    assert(IsCrossed(*vector));
    assert(crossings.size() != 3);
    crossings.push_back(vector);
}

const std::vector<const Vector *>& Conder::getCrossings() const {
    return crossings;
}


size_t ConderHash::operator()(const Conder &conder) const {
    return Hash(conder);
}

size_t ConderHash::operator()(const Conder *const conder) const {
    return Hash(*conder);
}

size_t ConderHash::Hash(const Conder &conder) const {
    std::hash<float> floatHash;
    if (conder.RangeIsSet()) {
        return floatHash(conder.getLeftVector().getAngle());
    } else {
        return conder.getCoord().x + conder.getCoord().y * 10000;
    }
}
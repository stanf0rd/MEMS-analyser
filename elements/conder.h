#pragma once

#include <vector>
#include <utility>
#include <optional>
#include "matrix.hpp"
#include "vector.h"

using simple_matrix::Dot;
using VectorPair = std::pair<Vector, Vector>;


struct ConderSizes {
    int width;
    int height;
    int delta;
    ConderSizes(int w, int h, int d);
};


class Conder {
public:
    Conder(const Dot coord, const ConderSizes &sizes);
    ~Conder() = default;

    const Dot& getCoord() const;
    const ConderSizes& getSizes() const;

    bool RangeIsSet() const;
    void CountVectorRange(const Dot &vectorsBegin);
    const Vector& getLeftVector() const;
    const Vector& getRightVector() const;

    bool IsCrossed(const Vector &vector) const;
    void AddCrossing(const Vector * vector);
    const std::vector<const Vector *>& getCrossings() const;

    friend struct ConderHash;
private:
    Dot coord;  // left bottom dot
    const ConderSizes &sizes;

    std::optional<VectorPair> vectorRange;

    std::vector<const Vector *> crossings;
    // range of vectors, which crosses conder
};


struct ConderHash {
    size_t operator()(const Conder &conder) const;
    size_t operator()(const Conder *const conder) const;
    size_t Hash(const Conder &conder) const;
};

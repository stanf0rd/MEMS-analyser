#pragma once

#include "matrix.hpp"

using simple_matrix::Dot;

class Vector {
public:
    Vector() = default;
    Vector(Dot begin, Dot end);
    Vector(Dot begin, float angle, int endY);

    const Dot& getBegin() const;
    const Dot& getEnd() const;
    const float& getAngle() const;

private:
    Dot begin;
    Dot end;
    float angle;  // angle between vector and vertical line
    float CountAngle();
};

#pragma once

#include "matrix.hpp"

using simple_matrix::Dot;

class Vector {
public:
    Vector() = default;
    Vector(Dot begin, Dot end);
    Vector(Dot _begin, float _angle, int endY);
    const float& getAngle() const;
    const Dot& getBegin() const;
    const Dot& getEnd() const;
private:
    Dot begin;
    Dot end;
    float angle;
    // angle between vector and vertical line
    float CountAngle();
};

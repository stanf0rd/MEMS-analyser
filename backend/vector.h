#pragma once

#include "matrix.hpp"

using simple_matrix::Dot;

class Vector {
public:
    Vector(Dot begin, Dot end);
    const float& getAngle() const;
private:
    Dot beginDot;
    Dot endDot;
    float angle;
    // angle between vector and vertical line
    float CountAngle();
};

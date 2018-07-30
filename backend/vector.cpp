#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "vector.h"

using std::atan;
using std::abs;


Vector::Vector(Dot begin, Dot end)
: begin(begin), end(end) {
    CountAngle();
}


float Vector::CountAngle() {
    int opposCatet = begin.x - end.x;
    int contCatet = begin.y - end.y;
    angle = atan(static_cast<float>(opposCatet)/static_cast<float>(contCatet));
    angle *= 180/static_cast<float>(M_PI);
    // std::cout << "opposCatet = " << opposCatet
    //           << "; contCatet = " << contCatet
    //           << "; angle = " << angle
    //           << std::endl;
    return angle;
}

const Dot& Vector::getBegin() const {
    return begin;
}

const Dot& Vector::getEnd() const {
    return end;
}

const float& Vector::getAngle() const {
    return angle;
}

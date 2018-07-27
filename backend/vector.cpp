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
    int opposCatet = abs(begin.x - end.x);
    int contCatet = begin.y - end.y;
    std::cout << "opposCatet = " << opposCatet << "; contCatet " << contCatet << std::endl;
    float angle = atan((float)opposCatet/(float)contCatet);
    angle *= 180/M_PI;
    return angle;
}

const Dot& Vector::getBegin() const {
    return begin;
}

const Dot& Vector::getEnd() const {
    return end;
}

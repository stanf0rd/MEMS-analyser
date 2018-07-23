#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "vector.h"

using std::atan;
using std::abs;


Vector::Vector(Dot begin, Dot end)
: beginDot(begin), endDot(end) {
    CountAngle();
}


float Vector::CountAngle() {
    int opposCatet = abs(beginDot.x - endDot.x);
    int contCatet = beginDot.y - endDot.y;
    std::cout << "opposCatet = " << opposCatet << "; contCatet " << contCatet << std::endl;
    float angle = atan((float)opposCatet/(float)contCatet);
    angle *= 180/M_PI;
    return angle;
}

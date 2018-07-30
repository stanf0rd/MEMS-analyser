#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "vector.h"

using std::tanf;
using std::atanf;
using std::abs;
using std::round;


Vector::Vector(Dot begin, Dot end)
: begin(begin), end(end) {
    CountAngle();
}

Vector::Vector(Dot _begin, float _angle, int endY)
: begin(_begin), angle(_angle) {
    int contCatet = begin.y - endY;
    int opposCatet = round(tan(angle*M_PI/180) * contCatet);
    int endX = begin.x + opposCatet;
    end = Dot(endX, endY);
}

float Vector::CountAngle() {
    int opposCatet = end.x - begin.x;
    int contCatet = begin.y - end.y;
    angle = atanf(static_cast<float>(opposCatet)/static_cast<float>(contCatet));
    angle *= 180/static_cast<float>(M_PI);
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

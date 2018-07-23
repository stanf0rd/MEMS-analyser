#pragma once

#include "matrix.hpp"

class Vector {
    public:
    private:
        Dot beginDot;
        Dot endDot;
        float angle;
        Vector(Dot, Dot);
        ~Vector();
//      static float countAngle(int, int);
};

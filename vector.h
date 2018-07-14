#pragma once

class Vector {
    public:
        int getEndX();
        int getEndY();
        static int getCount();
        static void setCount(int);
        static Vector** array;
        static void GenVectors();
    private:
        int endY;
        int endX;
        float angle;
        static int count;
        Vector(int);
        ~Vector();
//      static float countAngle(int, int);
};

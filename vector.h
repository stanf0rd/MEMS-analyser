#pragma once

class vector {
    public:
        int getEndX();
        int getEndY();
        static int getCount();
        static void setCount(int);
        static vector** array;
        static void genVectors();
    private:
        int endY;
        int endX;
        float angle;
        static int count;
        vector(int);
        ~vector();
//      static float countAngle(int, int);
};

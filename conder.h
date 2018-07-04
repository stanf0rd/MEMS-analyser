#pragma once

class conder {
    public:
        // int crossCount;
        // vector** firstCross;
        int getX();
        int getY();
        static int getWidth();
        static int getHeight();
        static int getDelta();
        static int getCount();
        static conder** array;
        static void setConderSizes(int, int, int);
        static conder** genConders(int);
    private:
        int x;
        int y;
        static int width;
        static int height;
        static int delta;  // free space between conders
        static int count;
        conder(int, int);
        ~conder();
};

#ifndef ELEMENTS
#define ELEMENTS

class conder {
	public:
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
		static int delta; //free space between conders
		static int count;
		conder(int, int);
		~conder();
};

class vector {
	public:
		int getEndX();
		static int getEndY();
		static int getCount();
		static void setCount(int);
		static vector** genVectors();
	private:
		static int count;
		static int endY;
		int endX;
		float angle;
		vector(int);
		~vector();
//		static float countAngle(int, int);
};

#endif
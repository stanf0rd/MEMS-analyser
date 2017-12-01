#include "elements.hpp"
#include "iostream"
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

extern int windowHeight;
extern int windowWidth;
vector** vector::array = NULL;
int vector::count;

static float countAngle(int, int);
int vector::getEndX() {return endX;}
int vector::getEndY() {return endY;}
int vector::getCount() {return count;}
void vector::setCount(int c) {count = c;}

vector::vector(int X) {
	endX = X;
	endY = windowHeight;
	angle = countAngle(endX, endY);
	cout << angle << endl;
//	cout << "vector created" << endl;
}

void vector::genVectors() {
	array = new vector*[count];
	for (int i=0; i<count; i++) {
		//генерация конечной точки вектора
		array[i] = new vector(-1400 + (rand()%2800));
	}
	// check()
}
/*
	x = X-windowWidth/2;
	y = Y;
	float leftAngle, rightAngle;
	if (x < 0) leftAngle = countAngle(x, y);
	else leftAngle = countAngle(x, y+height);

	if (x + width < 0) rightAngle = countAngle(x+width, y+height);
	else rightAngle = countAngle(x+width, y);

	cout << "leftAngle = " << leftAngle << endl;
	cout << "rightAngle = " << rightAngle << endl;
	count++;
*/

float countAngle(int x, int y) {
	int opposCatet = x;
//	int contCatet = y+windowHeight/3;
	int contCatet = y;
	//cout << "x = " << opposCatet << " y " << contCatet << endl;
	float angle = atan((float)opposCatet/(float)contCatet);
	return angle*180/M_PI;
}
#include "vector.h"
#include <iostream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

extern int windowHeight;
extern int windowWidth;
Vector** Vector::array = NULL;
int Vector::count;

static float countAngle(int, int);
int Vector::getEndX() {return endX;}
int Vector::getEndY() {return endY;}
int Vector::getCount() {return count;}
void Vector::setCount(int c) {count = c;}

Vector::Vector(int X) {
	endX = X;
	endY = windowHeight;
	angle = countAngle(endX, endY);
	cout << angle << endl;
//	cout << "Vector created" << endl;
}

void Vector::GenVectors() {
	array = new Vector*[count];
	for (int i=0; i<count; i++) {
		//генерация конечной точки вектора
		array[i] = new Vector(-1400 + (rand()%2800));
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
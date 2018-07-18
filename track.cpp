/* #include "track.h"
#include <iostream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

extern int windowHeight;
extern int windowWidth;
Track** Track::array = NULL;
int Track::count;

static float countAngle(int, int);
int Track::getEndX() {return endX;}
int Track::getEndY() {return endY;}
int Track::getCount() {return count;}
void Track::setCount(int c) {count = c;}

Track::Track(int X) {
	endX = X;
	endY = windowHeight;
	angle = countAngle(endX, endY);
	cout << angle << endl;
//	cout << "Track created" << endl;
}

void Track::GenTracks() {
	array = new Track*[count];
	for (int i=0; i<count; i++) {
		//генерация конечной точки вектора
		array[i] = new Track(-1400 + (rand()%2800));
	}
	// check()
} */
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

/* float countAngle(int x, int y) {
	int opposCatet = x;
//	int contCatet = y+windowHeight/3;
	int contCatet = y;
	//cout << "x = " << opposCatet << " y " << contCatet << endl;
	float angle = atan((float)opposCatet/(float)contCatet);
	return angle*180/M_PI;
} */
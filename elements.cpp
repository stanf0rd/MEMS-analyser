#include "stdafx.h"
#include "elements.hpp"
#include "iostream"
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int conder::sum = 0;
int conder::width = 60;
int conder::height = 20;
int conder::delta = 5;
int conder::count = 0;
conder** conder::array = NULL;

conder::conder(int X, int Y) {
	x = X;
	y = Y;
	count++;
//	cout << "conder created" << endl;
}

conder::~conder() {
	count--;
//	cout << "conder removed" << endl;
}

int conder::getX() {return x;}
int conder::getY() {return y;}
int conder::getWidth() {return width;}
int conder::getHeight() {return height;}
int conder::getDelta() {return delta;}
int conder::getCount() {return count;}

void conder::setConderSizes(int w, int h, int d) {
	width = w;
	height = h;
	delta = d;
}

conder** conder::genConders(int count) {
	srand(time(NULL));
	extern int windowWidth, windowHeight;
	array = new conder*[count];
	int x, y, tec = 0;
	int condGenPlaceWidth = windowWidth - 2*delta - width;
	int condGenPlaceHeight = windowHeight * 2/3 - height;
	for (int i = 0; i < count; i++) {
		x = rand() % (condGenPlaceWidth);
		y = rand() % (condGenPlaceHeight);
		if (checkPlace(x, y) == 1) {
			array[i] = new conder(x, y);
			tec = 0; }
		else {
			if (tec++ > 100000) break;
			i--;
		}
	}
	cout << sum << endl;
	return array;
}

int conder::checkPlace(int x, int y) {
	for (int i = 0; i < count; i++) {
		if (x >= array[i]->x - width - delta &&
			x <= array[i]->x + width + delta &&
			y >= array[i]->y - height - delta &&
			y <= array[i]->y + height + delta) {
				sum += i;
				return 0;
			}
		}
	sum += count;
	return 1;
}

int vector::endY;
int vector::count;

vector::vector(int X) {
	endX = X;
//	cout << "vector created" << endl;
}

int vector::getEndX() {return endX;}
int vector::getEndY() {return endY;}
int vector::getCount() {return count;}
void vector::setCount(int c) {count = c;}

vector** vector::genVectors() {
	extern int windowHeight;
	vector::endY = windowHeight;
	vector** array = new vector*[count];
	for (int i=0; i<count; i++) {
		//генерация конечной точки вектора
		array[i] = new vector(-1400 + (rand()%2800));
/*		for (int j=0; j<count; j++) {
			//вычисление координат точки вектора, лежащей на одной прямой с верхней частью кондера
			endY = conders[j]->getY();
			endX = endY*xEnd/VECTOR_END_Y;
			//проверка совпадения найденной точки вектора и верхней части кондера
			if ((endX < conders[j]->getX()) || 
				(endX > conders[j]->getX() + conder::getWidth())) continue;
#ifdef ONLY_ONE_CROSSING
			if (endY < vectors[i].endY) {
				if (vectors[i].endY == VECTOR_END_Y) 
					crossingsArray[crossingsCount++].angle = countAngle(xEnd, VECTOR_END_Y);
				vectors[i].endX = endX;
				vectors[i].endY = endY;
			}
#else
			crossingsArray[crossingsCount++].angle = countAngle(xEnd, VECTOR_END_Y);
#endif 
		}*/
	}
	return array;
}

/*float vector::countAngle(int xLength, int yLength) {
	//подсчёт угла
	int opposCatet = abs(xLength);
	int contCatet = yLength;
	float angle = atan((float)contCatet/opposCatet);
	return angle*180/M_PI;
}*/
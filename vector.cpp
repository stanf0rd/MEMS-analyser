#include "elements.hpp"
#include "iostream"
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
 
using namespace std;

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
#include "stdafx.h"
#include <GL/glut.h>
#include <iostream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define ONLY_ONE_CROSSING
#define _USE_MATH_DEFINES

#define VECTOR_END_Y 720

using namespace std;

void draw();
void genFlat();
void genVectors();
float countAngle(int, int);

struct mems_dim {
	int length;
	int pl_width;
	int delta;
};

struct mems {
	int x;
	int y;
};

struct vector {
	int endX;
	int endY;
	float angle;
};

struct crossing {
	float angle;
};

struct mems_dim flat {60, 8, 8};

mems *mems_xy;
vector *vectorArray;
crossing *crossingsArray;

int conderCount;
int vectorCount;
int crossingsCount;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	if (argc == 1) {
		vectorCount = conderCount = 10;
		cout << "No args, conders and vectors amounts set to default (10).\n";
	} else if (argc == 3) {
		conderCount = atoi(argv[1]);
		vectorCount = atoi(argv[2]);
		if (conderCount < 1) {
			conderCount = 10;
			cout << "Wrong conders count, set to default (10).\n"; }
		if (conderCount > 70) {
			cout << "Too much conders, set to max (70)\n"; 
			conderCount = 70; }
		if (vectorCount < 1) {
			vectorCount = 10;
			cout << "Wrong vectors count, set to default (10).\n"; }
		if (vectorCount > 1000) {
			cout << "Too much vectors, set to max (1000)\n"; 
			vectorCount = 1000; }
	} else {
		cout << "[programm call] [conders amount] [vectors amount]\n";
		cout << "Example: ./a.out 20 7\n";
		exit(0);
	}
		
	mems_xy = new mems[conderCount];
	vectorArray = new vector[vectorCount];
	if (conderCount < 20) crossingsCount = conderCount*vectorCount;
	else crossingsCount = 20 * vectorCount;
	crossingsArray = new crossing[crossingsCount]; 

	genFlat();
	genVectors();
		
	//GLUT init
	glutInit(&argc, argv);
	glutInitWindowSize(800, 720);
	glutInitWindowPosition(550, 0); 
	glutCreateWindow("MEMS Analyser v0.9.6");
	glOrtho(0.0, 800, 720, 0.0, 0.0, 1.0);
	glTranslated(400, 0, 0);
	glutDisplayFunc(draw);
		
	for (int i=0; i<crossingsCount; i++)
	cout << "Crossing found! Angle is " << crossingsArray[i].angle << "\n";
		
	glutMainLoop();
}

//glut init
void draw() {
	//cool white polygon (for adequate window resizing)
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(-400, 0);
	glVertex2i(400, 0);
	glVertex2i(400, 720);
	glVertex2i(-400, 720);
	glEnd();

	//vectors
	if (vectorCount > 70) glLineWidth(1);
	else glLineWidth(2);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (int i=0; i<vectorCount; i++) {
		glVertex2f(0, 0);
		glVertex2f(vectorArray[i].endX, vectorArray[i].endY); 
	}
	glEnd();
		
	//conders
	glColor3ub(128, 128, 128);
	for (int i = 0; i < conderCount; i++) {
		glBegin(GL_POLYGON);
		glVertex2i(mems_xy[i].x, mems_xy[i].y);
		glVertex2i(mems_xy[i].x + flat.length, mems_xy[i].y);
		glVertex2i(mems_xy[i].x + flat.length, mems_xy[i].y + flat.pl_width);
		glVertex2i(mems_xy[i].x, mems_xy[i].y + flat.pl_width);
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex2i(mems_xy[i].x, mems_xy[i].y + flat.pl_width + flat.delta);
		glVertex2i(mems_xy[i].x + flat.length, mems_xy[i].y + flat.pl_width + flat.delta);
		glVertex2i(mems_xy[i].x + flat.length, mems_xy[i].y + flat.delta + 2*flat.pl_width);
		glVertex2i(mems_xy[i].x, mems_xy[i].y + flat.delta + 2*flat.pl_width);
		glEnd();
	}
	glFlush();
}

void genFlat() {
	int i, j;
	for (i = 0; i < conderCount; i++) {
		mems_xy[i].x = rand() % 720 - 400;
		mems_xy[i].y = 200 + rand() % 480;
		for (j = 0; j < i; j++) {
			if (mems_xy[i].x >= mems_xy[j].x - flat.length - 2 * flat.delta &&
				mems_xy[i].y >= mems_xy[j].y - 2 * flat.pl_width - 2 * flat.delta &&
				mems_xy[i].x <= mems_xy[j].x + flat.length + 2 * flat.delta &&
				mems_xy[i].y <= mems_xy[j].y + 2 * flat.pl_width + 2 * flat.delta) {
					--i;
					break;
			}
		}
	}
}

void genVectors() {
	crossingsCount=0;
	for (int i=0; i<vectorCount; i++) {
		//генерация конечной точки вектора
		int xEnd = -1400 + (rand()%2800);
		vectorArray[i].endX = xEnd; 
		vectorArray[i].endY = VECTOR_END_Y;
		
		int xVectorCoord, yVectorCoord;
		for (int j=0; j<conderCount; j++) {
			//вычисление координат точки вектора, лежащей на одной прямой с верхней частью кондера
			yVectorCoord = mems_xy[j].y;
			xVectorCoord = yVectorCoord*xEnd/VECTOR_END_Y;
			//проверка совпадения найденной точки вектора и верхней части кондера
			if ((xVectorCoord < mems_xy[j].x) || 
				(xVectorCoord > mems_xy[j].x + flat.length)) continue;
#ifdef ONLY_ONE_CROSSING	
			if (yVectorCoord < vectorArray[i].endY) {
				if (vectorArray[i].endY == VECTOR_END_Y) 
					crossingsArray[crossingsCount++].angle = countAngle(xEnd, VECTOR_END_Y);
				vectorArray[i].endX = xVectorCoord;
				vectorArray[i].endY = yVectorCoord;
			}
#else
			crossingsArray[crossingsCount++].angle = countAngle(xEnd, VECTOR_END_Y);
#endif
		}
	}
}

float countAngle(int xLength, int yLength) {
	//подсчёт угла
	int opposCatet = abs(xLength);
	int contCatet = yLength;
	float angle = atan((float)contCatet/opposCatet);
	return angle*180/M_PI;
}
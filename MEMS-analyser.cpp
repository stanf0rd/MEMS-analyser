﻿#include "stdafx.h"
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <time.h>
#include "locale.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define ONLY_ONE_CROSSING

#define VECTOR_END_Y 720

using namespace std;

//conder is for condensator

void draw();
void genConders();
void genVectors();
float countAngle(int, int);

struct condDim {
	int length;
	int pl_width;
	int delta;
};

struct conder {
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

struct condDim flat {60, 8, 8};

conder *conderCoords;
vector *vectorsArray;
crossing *crossingsArray;

int conderCount;
int vectorCount;
int crossingsCount;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	

	string inputLine;
	if (argc == 1) {	
		cout << "Число конденсаторов: ";
		getline(cin, inputLine); } 
	else if (argc == 3) inputLine = argv[1];
	else {
		cout << "[вызов программы] [число конденсаторов] [число векторов]\n";
		cout << "Пример: ./a.out 20 7\n";
		exit(0); }
	try {
		conderCount = stoi(inputLine, NULL, 10);
		if (conderCount > 70) throw out_of_range("Слишком много конденсаторов.");}
	catch (invalid_argument) {
		if (inputLine.length()) cout << "Неверный ввод. ";
		cout << "Установлено число конденсаторов по умолчанию (10)." << endl;
		conderCount = 10; }
	catch (out_of_range) {
		cout << "Слишком много конденсаторов, установлен максимум (70)." << endl; 
		conderCount = 70; 
	}

	if (argc == 1) {
		cout << "Число векторов: ";
		getline(cin, inputLine); } 
	else if (argc == 3) inputLine = argv[2];
	try {
		vectorCount = stoi(inputLine, NULL, 10);
		if (vectorCount > 1000) throw out_of_range("Слишком много векторов."); }
	catch (invalid_argument) {
		if (inputLine.length()) cout << "Неверный ввод. ";
		cout << "Установлено число векторов по умолчанию (10)." << endl;
		vectorCount = 10; }
	catch (out_of_range) {
		cout << "Слишком много векторов, установлен максимум (1000)." << endl; 
		vectorCount = 1000; 
	}

	conderCoords = new conder[conderCount];
	vectorsArray = new vector[vectorCount];
	if (conderCount < 20) crossingsCount = conderCount*vectorCount;
	else crossingsCount = 20 * vectorCount;
	crossingsArray = new crossing[crossingsCount]; 

	genConders();
	genVectors();
		
	//GLUT init
	glutInit(&argc, argv);
	glutInitWindowSize(800, 720);
	glutInitWindowPosition(550, 0);
	glutCreateWindow("MEMS Analyser v1.0");
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
		glVertex2f(vectorsArray[i].endX, vectorsArray[i].endY);
	}
	glEnd();
		
	//conders
	glColor3ub(128, 128, 128);
	for (int i = 0; i < conderCount; i++) {
		glBegin(GL_POLYGON);
		glVertex2i(conderCoords[i].x, conderCoords[i].y);
		glVertex2i(conderCoords[i].x + flat.length, conderCoords[i].y);
		glVertex2i(conderCoords[i].x + flat.length, conderCoords[i].y + flat.pl_width);
		glVertex2i(conderCoords[i].x, conderCoords[i].y + flat.pl_width);
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex2i(conderCoords[i].x, conderCoords[i].y + flat.pl_width + flat.delta);
		glVertex2i(conderCoords[i].x + flat.length, conderCoords[i].y + flat.pl_width + flat.delta);
		glVertex2i(conderCoords[i].x + flat.length, conderCoords[i].y + flat.delta + 2*flat.pl_width);
		glVertex2i(conderCoords[i].x, conderCoords[i].y + flat.delta + 2*flat.pl_width);
		glEnd();
	}
	glFlush();
	glutPostRedisplay();
}

void genConders() {
	int i, j;
	for (i = 0; i < conderCount; i++) {
		conderCoords[i].x = rand() % 720 - 400;
		conderCoords[i].y = 200 + rand() % 480;
		for (j = 0; j < i; j++) {
			if (conderCoords[i].x >= conderCoords[j].x - flat.length - 2 * flat.delta &&
				conderCoords[i].y >= conderCoords[j].y - 2 * flat.pl_width - 2 * flat.delta &&
				conderCoords[i].x <= conderCoords[j].x + flat.length + 2 * flat.delta &&
				conderCoords[i].y <= conderCoords[j].y + 2 * flat.pl_width + 2 * flat.delta) {
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
		vectorsArray[i].endX = xEnd; 
		vectorsArray[i].endY = VECTOR_END_Y;
		
		int xVectorCoord, yVectorCoord;
		for (int j=0; j<conderCount; j++) {
			//вычисление координат точки вектора, лежащей на одной прямой с верхней частью кондера
			yVectorCoord = conderCoords[j].y;
			xVectorCoord = yVectorCoord*xEnd/VECTOR_END_Y;
			//проверка совпадения найденной точки вектора и верхней части кондера
			if ((xVectorCoord < conderCoords[j].x) || 
				(xVectorCoord > conderCoords[j].x + flat.length)) continue;
#ifdef ONLY_ONE_CROSSING	
			if (yVectorCoord < vectorsArray[i].endY) {
				if (vectorsArray[i].endY == VECTOR_END_Y) 
					crossingsArray[crossingsCount++].angle = countAngle(xEnd, VECTOR_END_Y);
				vectorsArray[i].endX = xVectorCoord;
				vectorsArray[i].endY = yVectorCoord;
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
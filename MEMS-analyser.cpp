#include "stdafx.h"
#include "elements.hpp"
#include <GL/glut.h>
//#include "SOIL/SOIL.h"
#include <iostream>
#include <string>

using namespace std;

//conder is for condensator

void draw();
void drawPolygon(int, int, int, int);

conder **conders;
vector **vectors;

int windowWidth = 800;
int windowHeight = 720;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Russian");
	int askedConderCount, askedVectorCount;
	string inputLine;
	
	if (argc == 1) {
		cout << "Число конденсаторов: ";
		getline(cin, inputLine); } 
	else if (argc == 3) inputLine = argv[1];
	else {
		cout << "[вызов программы] [число конденсаторов] [число векторов]\n";
		cout << "Пример: ./a.out 20 7\n";
		exit(0); }
	try {askedConderCount = stoi(inputLine, NULL, 10);}
	catch (invalid_argument) {
		if (inputLine.length()) cout << "Неверный ввод. ";
		cout << "Установлено число конденсаторов по умолчанию (10)." << endl;
		askedConderCount = 10; }
	catch (out_of_range) {
		cout << "Слишком много конденсаторов, установлен максимум (70)." << endl; 
		askedConderCount = 70;
	}
			
	if (argc == 1) {
		cout << "Число векторов: ";
		getline(cin, inputLine); } 
		else if (argc == 3) inputLine = argv[2];
		try {
			askedVectorCount = stoi(inputLine, NULL, 10);
	if (askedVectorCount > 1000) throw out_of_range("Слишком много векторов."); }
	catch (invalid_argument) {
		if (inputLine.length()) cout << "Неверный ввод. ";
		cout << "Установлено число векторов по умолчанию (10)." << endl;
		askedVectorCount = 10; }
	catch (out_of_range) {
		cout << "Слишком много векторов, установлен максимум (1000)." << endl; 
		askedVectorCount = 1000; 
	}
	vector::setCount(askedVectorCount);

	conder::setConderSizes(30, 10, 5);
	
	conders = conder::genConders(askedConderCount);
	vectors = vector::genVectors();
	
	//GLUT init
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(550, 0);
	glutCreateWindow("MEMS-Analyser[CPP] v0.1");
	glOrtho(0.0, windowWidth, windowHeight, 0.0, 0.0, 1.0);
	glTranslated(windowWidth/2, 0, 0);
	glutDisplayFunc(draw);

	cout << "Were created " << conder::getCount() << " conders" << endl;
	cout << "Were created " << vector::getCount() << " vectors" << endl;
		
	glutMainLoop();
	return 0;
}

//glut init
void draw() {
	//cool white polygon (for adequate window resizing)
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(-windowWidth/2, 0);
	glVertex2i(windowWidth/2, 0);
	glVertex2i(windowWidth/2, windowHeight);
	glVertex2i(-windowWidth/2, windowHeight);
	glEnd();

	//vectors
	if (vector::getCount() > 70) glLineWidth(1);
	else glLineWidth(2);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (int i=0; i<vector::getCount(); i++) {
		glVertex2f(0, 0);
		glVertex2f(vectors[i]->getEndX(), vector::getEndY());
	}
	glEnd();
		
	//conders
	glColor3ub(128, 128, 128);
	for (int i = 0; i < conder::getCount(); i++) {
		drawPolygon(
			conders[i]->getX() - windowWidth/2 + conder::getDelta(), 
			conders[i]->getY() + windowHeight/3, 
			conder::getWidth(), 
			conder::getHeight()
		);
	}
	//glFlush();
	glFinish();
}

void drawPolygon(int x, int y, int width, int height) {
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + width, y);
		glVertex2i(x + width, y + height);
		glVertex2i(x, y + height);
	glEnd();
}
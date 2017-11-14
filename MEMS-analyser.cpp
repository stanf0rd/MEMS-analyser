#include "stdafx.h"
#include "elements.hpp"
#include <GL/glut.h>
#include "SOIL/SOIL.h"
#include <iostream>
#include <string>

using namespace std;

//conder is for condensator

void draw();

conder **conders;
vector **vectors;

int windowWidth = 800;
int windowHeight = 720;

int main(int argc, char *argv[]) {

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
	glutInitWindowSize(800, 720);
	glutInitWindowPosition(550, 0);
	glutCreateWindow("MEMS-Analyser[CPP] v0.1");
	glOrtho(0.0, 800, 720, 0.0, 0.0, 1.0);
	glTranslated(400, 0, 0);
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
	glVertex2i(-400, 0);
	glVertex2i(400, 0);
	glVertex2i(400, 720);
	glVertex2i(-400, 720);
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
		glBegin(GL_POLYGON);
		glVertex2i(conders[i]->getX(), conders[i]->getY());
		glVertex2i(conders[i]->getX() + conder::getWidth(), conders[i]->getY());
		glVertex2i(conders[i]->getX() + conder::getWidth(), conders[i]->getY() + conder::getHeight());
		glVertex2i(conders[i]->getX(), conders[i]->getY() + conder::getHeight());
		glEnd();
	}
	//glFlush();
	glFinish();
}
#include "elements.hpp"
#include "iostream"
#include <time.h>
 
using namespace std;

short* conderMap;
int mapWidth;
int mapHeight;

static void fillMap(int, int);

int conder::width = 60;
int conder::height = 20;
int conder::delta = 5;
int conder::count = 0;
conder** conder::array = NULL;

conder::conder(int X, int Y) {
	x = X;
	y = Y;
	count++;
}

conder::~conder() {
	count--;
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
	array = new conder*[count];
	int x, y, tec = 0;
	extern int windowWidth, windowHeight;
	mapWidth = windowWidth - 2*delta - width;
	mapHeight = windowHeight * 2/3 - height - delta;
	conderMap = new short[mapWidth*mapHeight];
	for (int i=0; i<mapWidth*mapHeight; i++) conderMap[i] = 0;
	srand(time(NULL));
	int i = 0;
	while (i != count) {
		x = rand() % (mapWidth);
		y = rand() % (mapHeight);
		if (conderMap[y*(mapWidth-1)+x] == 0) {
			array[i++] = new conder(x, y);
			fillMap(x, y); }
		else if (tec++ > 20000) break;
	}
	delete conderMap;
	return array;
}

static void fillMap(int x, int y) {
	int startDotX = x - conder::getWidth() - conder::getDelta() + 1,
		startDotY = y - conder::getHeight() - conder::getDelta() + 1,
		stopDotX = x + conder::getWidth() + conder::getDelta(),
		stopDotY = y + conder::getHeight() + conder::getDelta();
	if (startDotX < 0) startDotX = 0;
	if (startDotY < 0) startDotY = 0;
	if (stopDotX > mapWidth) stopDotX = mapWidth;
	if (stopDotY > mapHeight) stopDotY = mapHeight;
	for (int i = startDotY; i < stopDotY; i++)
		for (int j = startDotX; j < stopDotX; j++)
			conderMap[i*(mapWidth-1) + (j)] = 1;
}
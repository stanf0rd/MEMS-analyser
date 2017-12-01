#include "elements.hpp"
#include "iostream"
#include <time.h>

using namespace std;

short* conderMap;
int mapWidth;
int mapHeight;

static void createConderMap();
static void fillMap(int, int);

int conder::width = 60;
int conder::height = 20;
int conder::delta = 5;
int conder::count = 0;
conder** conder::array = NULL;
extern int windowWidth, windowHeight;

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

conder** conder::genConders(int askedCount) {
	array = new conder*[askedCount];
	/*int mapSize = */createConderMap();
	int x, y, tec = 0, i = 0;
	srand(time(NULL));
	while (i != askedCount) {
		//conderMap coordinates
		x = rand() % (mapWidth);
		y = rand() % (mapHeight);
		if (conderMap[y*(mapWidth-1)+x] == 0) {
			fillMap(x, y); 
			//sending full window coordinates
			array[i++] = new conder(x+delta, y);
			cout << "for conder #" <<i<<" there are "<<tec<<" cats"<< endl;
			tec = 0;}
		else if (tec++ == 100000) { 
			cout << "Уместилось " << count << " конденсаторов." << endl;
			break;
		}
	}
	delete conderMap;
	return array;
}

static void fillMap(int x, int y) {
	int startDotX = x - conder::getWidth() - conder::getDelta(),
		startDotY = y - conder::getHeight() - conder::getDelta(),
		stopDotX = x + conder::getWidth() + conder::getDelta(),
		stopDotY = y + conder::getHeight() + conder::getDelta();
	if (startDotX < 0) startDotX = 0;
	if (startDotY < 0) startDotY = 0;
	if (stopDotX > mapWidth) stopDotX = mapWidth;
	if (stopDotY > mapHeight) stopDotY = mapHeight;
//	cout << "filled from " << startDotX << "x" << startDotY;
//	cout << " to " << stopDotX << "x" << stopDotY << endl;
	for (int i = startDotY; i < stopDotY; i++) {
		for (int j = startDotX; j < stopDotX; j++) {
			//cout << conderMap[i*(mapWidth-1) + j];
			conderMap[i*(mapWidth-1) + j] = 1;
		}
		//cout << endl;
	}
}

static void createConderMap() {
	mapWidth = windowWidth - conder::getDelta()*2 - conder::getWidth();
	mapHeight = windowHeight*2/3 - conder::getHeight() - conder::getDelta();
	conderMap = new short[mapWidth*mapHeight];
	for (int i=0; i<mapWidth*mapHeight; i++) 
		conderMap[i] = 0;
	//return mapWidth*mapHeight;
}
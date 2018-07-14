#include "conder_map.h"

ConderMapSizes::ConderMapSizes(const int _w, const int _h)
: width(_w)
, height(_h)
, offset(offset)
, topOffset(topOffset)
{}

ConderMap::ConderMap(const ConderMapSizes mSizes, const ConderSizes cSizes) 
: conderCount(0)
, conderSizes(cSizes)
, mapSizes(mSizes) {
    int matrixWidth = mapSizes.width - 2*mapSizes.offset - conderSizes.width;
    int matrixHeight = 2 * (mapSizes.height - mapSizes.offset) / 3;
    map = new Matrix<char>(matrixWidth, matrixHeight, true);
}

void ConderMap::GenConders(const int count) {
    
}

// void ConderMap::GenConders(int count) {
//     /*int mapSize = */createConderMap();
//     int x, y, tec = 0, i = 0;
//     srand(time(NULL));
//     while (i != askedCount) {
//         //conderMap coordinates
//         x = rand() % (mapWidth);
//         y = rand() % (mapHeight);
//         if (conderMap[y*(mapWidth-1)+x] == 0) {
//             fillMap(x, y); 
//             //sending full window coordinates
//             array[i++] = new Conder(x+delta, y);
//             cout << "for Conder #" <<i<<" there are "<<tec<<" cats"<< endl;
//             tec = 0;}
//         else if (tec++ == 100000) { 
//             cout << "Уместилось " << count << " конденсаторов." << endl;
//             break;
//         }
//     }
//     delete conderMap;
//     return array;
// }

// static void fillMap(int x, int y) {
//     int startDotX = x - Conder::getWidth() - Conder::getDelta(),
//         startDotY = y - Conder::getHeight() - Conder::getDelta(),
//         stopDotX = x + Conder::getWidth() + Conder::getDelta(),
//         stopDotY = y + Conder::getHeight() + Conder::getDelta();
//     if (startDotX < 0) startDotX = 0;
//     if (startDotY < 0) startDotY = 0;
//     if (stopDotX > mapWidth) stopDotX = mapWidth;
//     if (stopDotY > mapHeight) stopDotY = mapHeight;
// //  cout << "filled from " << startDotX << "x" << startDotY;
// //  cout << " to " << stopDotX << "x" << stopDotY << endl;
//     for (int i = startDotY; i < stopDotY; i++) {
//         for (int j = startDotX; j < stopDotX; j++) {
//             //cout << conderMap[i*(mapWidth-1) + j];
//             conderMap[i*(mapWidth-1) + j] = 1;
//         }
//         //cout << endl;
//     }
// }

// static void createConderMap() {
//     mapWidth = windowWidth - Conder::getDelta()*2 - Conder::getWidth();
//     mapHeight = windowHeight*2/3 - Conder::getHeight() - Conder::getDelta();
//     conderMap = new short[mapWidth*mapHeight];
//     for (int i=0; i<mapWidth*mapHeight; i++) 
//         conderMap[i] = 0;
//     //return mapWidth*mapHeight;
// }
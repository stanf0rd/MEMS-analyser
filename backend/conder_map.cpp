#include <ctime>
#include <cmath>
#include <iostream>

#include "conder_map.h"
#include "configuration.h"

ConderMapSizes::ConderMapSizes(const int _w, const int _h)
: width(_w)
, height(_h)
{
    auto &config = Configuration::Instance();
    offset = config.getOffset();
    topOffset = config.getTopOffset();
}

ConderMap::ConderMap(const ConderMapSizes mSizes, const ConderSizes cSizes)
: conderSizes(cSizes)
, mapSizes(mSizes)
, conderCount(0) {
    int matrixWidth = mapSizes.width - 2*mapSizes.offset - conderSizes.width;
    int matrixHeight = 2 * (mapSizes.height - mapSizes.offset) / 3;
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
}

int ConderMap::GenConders(const int count) {
    auto &matrix = *map;
    int x = 0, y = 0, i = 0, tec = 0;
    srand(time(nullptr));
    for (i = 0; i < count; i++) {
        x = rand() % (matrix.getWidth());
        y = rand() % (matrix.getHeight());
        Dot begin(x, y);
        Dot end(x + conderSizes.width, y + conderSizes.height);
        if (matrix[Dot(x, y)] == 0) {
            matrix.fill(begin, end, 1);

            Dot realBegin(begin + Dot(mapSizes.offset, mapSizes.offset));
            conders.push_back(Conder(realBegin, &conderSizes));

            std::cout << "for Conder #" << i << " there are " << tec << " cats" << std::endl;
            tec = 0;
        } else if (tec++ == 100000) {
            std::cout << "Уместилось " << i << " конденсаторов." << std::endl;
            break;
        } else {
            tec++;
            i--;
        }
    }
    conderCount = i;
    return i;
}

const vector<Conder>& ConderMap::getConders() const {
    return conders;
}


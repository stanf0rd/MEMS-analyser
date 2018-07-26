#include <cmath>
#include <iostream>
// TODO: is iostream needed here?

#include "conder_map.h"
#include "configuration.h"


ConderMapSizes::ConderMapSizes(const int _w, const int _h)
: width(_w)
, height(_h) {
    auto &config = Configuration::Instance();
    offset = config.getOffset();
    topOffset = config.getTopOffset();
}

ConderMap::ConderMap(const ConderMapSizes mSizes, const ConderSizes cSizes)
: conderSizes(cSizes)
, mapSizes(mSizes)
, conderCount(0) {
    int matrixWidth = mapSizes.width - 2*mapSizes.offset - conderSizes.width;
    int matrixHeight = (mapSizes.height - mapSizes.offset)
                     / 100 * (100 - mapSizes.topOffset);  // 100 means 100%
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
}

int ConderMap::GenConders(const int count) {
    auto const &config = Configuration::Instance();
    auto &matrix = *map;
    int x = 0, y = 0, i = 0, tec = 0;
    int offset = config.getOffset();
    for (i = 0; i < count; i++) {
        x = rand() % (matrix.getWidth());
        y = rand() % (matrix.getHeight());
        if (matrix[Dot(x, y)] == 0) {
            Dot begin(x - conderSizes.width - offset,
                      y - conderSizes.height - offset);
            Dot end(x + conderSizes.width + offset,
                    y + conderSizes.height + offset + 1);
            matrix.fill(begin, end, 1, true);

            Dot realBegin(Dot(x, y) + Dot(mapSizes.offset, mapSizes.offset));
            conders.push_back(Conder(realBegin, &conderSizes));

            std::cout << "For conder #" << i << " there are " << tec << " cats" << std::endl;
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
    std::cout << "ConderCount = " << i
         << "; vector size = " << conders.size() << std::endl;
    return i;
}

const vector<Conder>& ConderMap::getConders() const {
    return conders;
}


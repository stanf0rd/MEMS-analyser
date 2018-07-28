#include <cmath>
#include <cassert>
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
                     / 100 * (100 - mapSizes.topOffset);  // "100" means 100%
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
}

void ConderMap::setVectorsBegin(const Dot dot) {
    vectorsBegin = dot;
}

const Dot& ConderMap::getVectorsBegin() const {
    return vectorsBegin;
}

int ConderMap::GenConders(const int &count,
                          vector<Conder> &generatedConders) {
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

            const Dot realBegin(Dot(x, y) + Dot(mapSizes.offset, mapSizes.offset));
            generatedConders.push_back(Conder(realBegin, conderSizes));

            std::cout << "For conder #" << i << " there are " << tec << " cats" << std::endl;
            tec = 0;
        } else if (tec++ == 100000) {
            std::cout << i << " conders found their places." << std::endl;
            break;
        } else {
            tec++;
            i--;
        }
    }
    return conderCount = i;
}

void ConderMap::CountRanges(
    const Dot &tracksBegin,
    vector<Conder> &generatedConders)
{
    const auto &conderSizes = Configuration::Instance().getConderSizes();
    for (auto &conder : generatedConders) {
        const auto leftVectorEnd =
            (conder.getCoord().x <= tracksBegin.x) ?
            Dot(conder.getCoord() + Dot(0, conderSizes.height)) :
            Dot(conder.getCoord());
        auto leftVector = Vector(tracksBegin, leftVectorEnd);
        // std::cout << leftVector.getAngle();
        const auto rightVectorEnd =
            (conder.getCoord().x + conderSizes.width <= tracksBegin.x) ?
            Dot(conder.getCoord() + Dot(conderSizes.width, 0)) :
            Dot(conder.getCoord() + Dot(conderSizes.width, conderSizes.height));
        auto rightVector = Vector(tracksBegin, rightVectorEnd);

        conder.setVectorRange(leftVector, rightVector);
        // std::cout << conder.getVectorRange().first.getAngle() << std::endl;
    }
}

void ConderMap::VectorToMap(const std::vector<Conder> &generatedConders) {
    for (auto conder : generatedConders) {
        auto &angle = conder.getVectorRange().first.getAngle();
        auto pair = std::make_pair(angle, conder);
        conders.emplace(pair);
    }
}

int ConderMap::GenVectors(const int &count) {
    assert(!conders.empty());
    // for (int i = 0; i != count; i++) {
        
    // }
    return 1;
}

const std::map<float, Conder>& ConderMap::getConders() const {
    return conders;
}

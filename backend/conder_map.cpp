#include <cmath>
#include <cassert>
#include <iostream>
#include <random>
#include <utility>
// TODO: is iostream needed here?

#include "conder_map.h"
#include "configuration.h"

using std::rand;

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
    // TODO: hardcode?
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
    // TODO: remove hardcode, make macros
    vectorsBegin = *new Dot(mapSizes.width/2, mapSizes.height);
}

ConderMap::~ConderMap() {
    delete map;
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

            // std::cout << "For conder #" << i << " there are " << tec << " cats" << std::endl;
            tec = 0;
        } else if (tec++ == 100000) {
            // std::cout << i << " conders found their places." << std::endl;
            break;
        } else {
            tec++;
            i--;
        }
    }
    return conderCount = i;
}

void ConderMap::CountRanges(vector<Conder> &generatedConders) {
    const auto &conderSizes = Configuration::Instance().getConderSizes();
    for (auto &conder : generatedConders) {
        const auto leftVectorEnd =
            (conder.getCoord().x <= vectorsBegin.x) ?
            Dot(conder.getCoord() + Dot(0, conderSizes.height)) :
            Dot(conder.getCoord());
        auto leftVector = Vector(vectorsBegin, leftVectorEnd);
        // std::cout << leftVector.getAngle();
        const auto rightVectorEnd =
            (conder.getCoord().x + conderSizes.width <= vectorsBegin.x) ?
            Dot(conder.getCoord() + Dot(conderSizes.width, 0)) :
            Dot(conder.getCoord() + Dot(conderSizes.width, conderSizes.height));
        auto rightVector = Vector(vectorsBegin, rightVectorEnd);

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
    int endDotX = 0, endDotY = 0, tries = 0, i = 0;
    for (i = 0; i != count; i++) {
        endDotX = rand() % (mapSizes.width*4) - mapSizes.width*1.5;
        auto vector = new Vector(vectorsBegin, Dot(endDotX, endDotY));
        const auto &angle = vector->getAngle();
        std::cout << "Angle of generated vector = " << angle << std::endl;
        auto found = conders.lower_bound(angle);
        if (found == conders.end()) found--;
        auto firstConder = found->second;
        // if ((firstConder.getVectorRange().second.getAngle() >= angle)  // conder crossed!
        // && (!firstConder.addCrossing(vector))) {  // too much crossings for 1 conder!
        //     --i;
        //     delete vector;
        //     if (tries++ > 10) return i;  // TODO: hardcode! maybe conderCount?
        //     continue;
        // }
        vectors.push_back(*vector);
    }

    return i;
}

const std::map<float, Conder>& ConderMap::getConders() const {
    return conders;
}

const std::vector<Vector>& ConderMap::getVectors() const {
    return vectors;
}

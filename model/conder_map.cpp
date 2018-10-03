/* by stanford */

// #include <cmath>
#include <cassert>
#include <utility>  // make_pair
#include <cstdlib>  //std::rand
#include <unordered_set>

#include "conder_map.hpp"
#include "fieldwidget.hpp"
#include "configuration.hpp"

#include <iostream>

ConderMap::ConderMap(const Configuration &config)
: conderSizes(config.conderSizes)
, fieldSizes(config.fieldSizes)
{
    int matrixWidth = fieldSizes.width - 2*fieldSizes.offset - conderSizes.width;
    int matrixHeight = (fieldSizes.height - fieldSizes.offset)
                     / 100 * (100 - fieldSizes.topOffset);  // "100" means 100%
    // TODO: hardcode?
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
    // TODO: remove hardcode, make macros
    vectorsBegin = Dot(fieldSizes.width/2, fieldSizes.height);
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


int ConderMap::GenConders(const int &count) {
    auto &matrix = *map;
    int x = 0, y = 0, i = 0, tec = 0;
    int offset = fieldSizes.offset;

    for (i = 0; i < count; i++) {
        x = std::rand() % (matrix.getWidth());
        y = std::rand() % (matrix.getHeight());
        if (matrix[Dot(x, y)] == 0) {
            Dot begin(x - conderSizes.width - offset,
                      y - conderSizes.height - offset);
            Dot end(x + conderSizes.width + offset,
                    y + conderSizes.height + offset + 1);
            matrix.fill(begin, end, 1, true);

            const Dot realBegin(Dot(x, y) + Dot(fieldSizes.offset, fieldSizes.offset));
            conders.push_back(Conder(realBegin, conderSizes));

            // std::cout << "For conder #" << i << " there are " << tec << " cats" << std::endl;
            tec = 0;
        } else if (tec++ == 100000) {  // TODO: clean up
            // std::cout << i << " conders found their places." << std::endl;
            break;
        } else {
            tec++;
            i--;
        }
    }
    return conderCount = i;
}


void ConderMap::CountRanges() {
    for (auto &conder : conders) {
        conder.CountVectorRange(vectorsBegin);
    }
}


#include <iostream>  // TODO: wtf

int ConderMap::GenVectors(const int &count) {
    assert(!conders.empty());
    float maxAngle = abs(Vector(vectorsBegin, Dot(0, map->getHeight())).getAngle());

    int i = 0, failures = 0;
    for (i = 0; i != count; i++) {
        float angle = static_cast<float>(rand())
                    / static_cast<float>(RAND_MAX)
                    * maxAngle * 2 - maxAngle;
        Vector vector(vectorsBegin, angle, -2000);  // TODO: hardcode
        vectors.push_back(vector);

        std::vector<Conder *> crossedConders;
        for (auto &conder : conders) {
            if (!conder.IsCrossed(vector)) continue;
            if (conder.getCrossings().size() == 3) {  // TODO: hardcode
                vectors.pop_back();
                i--;
                if (++failures == conderCount) break;  // he-he
                else continue;
            } else {
                crossedConders.push_back(&conder);
            }
        }

        if (failures == conderCount) break;
        for (auto &conder : crossedConders)
            conder->AddCrossing(&vector);
    }

    return i;
}

const std::vector<Conder>& ConderMap::getConders() const {
    return conders;
}

const std::vector<Vector>& ConderMap::getVectors() const {
    return vectors;
}

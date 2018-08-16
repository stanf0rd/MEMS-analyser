// #include <cmath>
#include <cassert>
#include <utility>  // make_pair
#include <cstdlib>  //std::rand
#include <unordered_set>

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
{
    int matrixWidth = mapSizes.width - 2*mapSizes.offset - conderSizes.width;
    int matrixHeight = (mapSizes.height - mapSizes.offset)
                     / 100 * (100 - mapSizes.topOffset);  // "100" means 100%
    // TODO: hardcode?
    map = new Matrix<bool>(matrixWidth, matrixHeight, true);
    // TODO: remove hardcode, make macros
    vectorsBegin = Dot(mapSizes.width/2, mapSizes.height);
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
    int offset = mapSizes.offset;

    for (i = 0; i < count; i++) {
        x = std::rand() % (matrix.getWidth());
        y = std::rand() % (matrix.getHeight());
        if (matrix[Dot(x, y)] == 0) {
            Dot begin(x - conderSizes.width - offset,
                      y - conderSizes.height - offset);
            Dot end(x + conderSizes.width + offset,
                    y + conderSizes.height + offset + 1);
            matrix.fill(begin, end, 1, true);

            const Dot realBegin(Dot(x, y) + Dot(mapSizes.offset, mapSizes.offset));
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



int ConderMap::GenVectors(const int &count) {
    assert(!conders.empty());
    float maxAngle = abs(Vector(vectorsBegin, Dot(0, map->getHeight())).getAngle());

    int i = 0;
    for (i = 0; i != count; i++) {
        int failures = 0;
        float angle = static_cast<float>(rand())
                    / static_cast<float>(RAND_MAX)
                    * maxAngle * 2 - maxAngle;
        auto vector = new Vector(vectorsBegin, angle, -2000);  // TODO: hardcode
        vectors.push_back(*vector);

        std::vector<Conder *> crossedConders;
        for (auto &conder : conders) {
            if (!conder.IsCrossed(*vector)) continue;
            if (conder.getCrossings().size() != 3) {  // TODO: hardcode
                crossedConders.push_back(&conder);
            } else {
                vectors.pop_back();
                if (++failures == conderCount) break;  // he-he
                else continue;
            }
        }

        if (failures == conderCount) break;
        for (auto &conder : crossedConders) {
            conder->AddCrossing(vector);
        }
    }

    return i;
}

const std::vector<Conder>& ConderMap::getConders() const {
    return conders;
}

const std::vector<Vector>& ConderMap::getVectors() const {
    return vectors;
}

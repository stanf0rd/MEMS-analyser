/* by stanford */
#pragma once

#include <vector>

#include "configuration.hpp"
#include "conder.hpp"
#include "matrix.hpp"

using simple_matrix::Matrix;


class ConderMap {
public:
    ConderMap(const Configuration &);
    ~ConderMap();

    void setVectorsBegin(const Dot dot);
    const Dot& getVectorsBegin() const;

    int GenConders(const int &count);
    void CountRanges();

    int GenVectors(const int &count);

    const std::vector<Conder>& getConders() const;
    const std::vector<Vector>& getVectors() const;

private:
    const ConderSizes conderSizes;
    const FieldSizes fieldSizes;

    Matrix<bool> *map;

    int conderCount;
    int vectorCount;
    std::vector<Conder> conders;
    std::vector<Vector> vectors;
    Dot vectorsBegin;
};

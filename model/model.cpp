/* by stanford */

#include "model.hpp"


Model::Model(const Configuration &_conf)
: config(new Configuration(_conf))
, map(nullptr)
{
    srand(time(nullptr));       // for conder generation
}

Model::~Model() {
    delete map;
    delete config;
}

bool Model::GenerateScene() {
    delete map;
    map = new ConderMap(*config);
    map->GenConders(config->askedConderCount);
    // Dot vectorsBegin(this->width()/2, this->height());
    map->CountRanges();
    std::cout << map->GenVectors(config->askedVectorCount) << endl;
    return true;
}

void Model::SetConfig(const Configuration &_config) {
    if (config) delete config;
    config = new Configuration(_config);
}

const std::vector<Conder>& Model::getConders() const {
    return map->getConders();
}

const std::vector<Vector>& Model::getVectors() const {
    return map->getVectors();
}

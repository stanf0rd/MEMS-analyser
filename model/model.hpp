#include "fieldwidget.hpp"
#include "configuration.hpp"
#include "conder_map.hpp"
#include "leak_counter.hpp"

class Model {
public:
    Model(const Configuration &);
    ~Model();
    void SetConfig(const Configuration &);
    bool GenerateScene();
    void CountAngles();
    const std::vector<Conder>& getConders() const;
    const std::vector<Vector>& getVectors() const;

private:
    Configuration *config;
    ConderMap *map;
    LeakCounter counter;
};

// TODO: FIXME: create class with angles
// Put as private object to model

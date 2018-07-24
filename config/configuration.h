/* by stanford */

#include "conder.h"
#include "config.h"

class Configuration {
public:
    static Configuration& Instance();
    void Update();
    const ConderSizes& getConderSizes() const;
    const int& getOffset() const;
    const int& getTopOffset() const;
private:
    ConderSizes conderSizes;
    int offset;
    int topOffset;
    int askedConderCount;
    int vectorCount;

    Configuration();
    ~Configuration() = default;
    void ReadConfigFile();

    // deny coping
    Configuration(Configuration const&) = delete;
    Configuration& operator= (Configuration const&) = delete;
};

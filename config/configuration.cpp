/* by stanford */
#include "configuration.hpp"


FieldSizes::FieldSizes(
    int _width,
    int _height,
    int _offset,
    int _topOffset)
: width(_width)
, height(_height)
, offset(_offset)
, topOffset(_topOffset)
{}

// FieldSizes& FieldSizes::operator=(const FieldSizes &old) {
//     width = old.width;
//     height = old.height;
//     offset = old.offset;
//     topOffset = old.topOffset;
//     return (*this);
// }


bool FieldSizes::isValid() const {
    return true;
}


Configuration::Configuration(
    FieldSizes fSizes,
    ConderSizes cSizes,
    int conderCount,
    int vectorCount)
: fieldSizes(fSizes)
, conderSizes(cSizes)
, askedConderCount(conderCount)
, askedVectorCount(vectorCount)
{}

// Configuration& Configuration::operator=(const Configuration &old) {
//     return (*this);  // TODO: is this right?  //FIXME: no
// }

bool Configuration::isValid() const {
    return true;
}

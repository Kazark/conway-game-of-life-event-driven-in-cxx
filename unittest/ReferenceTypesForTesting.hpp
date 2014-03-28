#ifndef _REFERENCETYPESFORTESTING_HPP_
#define _REFERENCETYPESFORTESTING_HPP_

#include "ReferenceType.hpp"

struct XXX : public ::EventArchitecture::ReferenceType {
    XXX(int x) : x(x) {}
    int x;
};

struct YYY: public ::EventArchitecture::ReferenceType {};

struct ZZZ: public ::EventArchitecture::ReferenceType {
    ZZZ(XXX xxx, YYY yyy) : xxx(xxx), yyy(yyy) {}
    XXX xxx;
    YYY yyy;
};

#endif

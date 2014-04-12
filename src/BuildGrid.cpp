#include "BuildGrid.hpp"
using namespace ::ConwayGameOfLife;

BuildGrid BuildGrid::OfSize(int) {
    return BuildGrid();
}

bool BuildGrid::finished() {
    return false;
}

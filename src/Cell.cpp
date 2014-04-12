#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

Cell::Cell() :
    isLiving(),
    position(),
    _grid(nullptr)
{}

Cell::Cell(Grid* grid) :
    isLiving(),
    position(),
    _grid(grid)
{}


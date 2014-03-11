#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

Cell::Cell() :
    _grid(nullptr)
{}

Cell::Cell(Grid* grid) :
    _grid(grid)
{}


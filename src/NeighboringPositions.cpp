#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;

NeighboringPositions::NeighboringPositions(CartesianPosition position) :
    my(position)
{}

CartesianPosition NeighboringPositions::northern() const
{
    return CartesianPosition(my.x, my.y - 1);
}

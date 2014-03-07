#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;

NeighboringPositions::NeighboringPositions(CartesianPosition position) :
    my(position)
{}

CartesianPosition NeighboringPositions::northern() const
{
    return CartesianPosition(my.x, my.y - 1);
}

CartesianPosition NeighboringPositions::northeastern() const
{
    return CartesianPosition(my.x + 1, my.y - 1);
}

CartesianPosition NeighboringPositions::eastern() const
{
    return CartesianPosition(my.x + 1, my.y);
}

CartesianPosition NeighboringPositions::southeastern() const
{
    return CartesianPosition(my.x + 1, my.y + 1);
}

CartesianPosition NeighboringPositions::southern() const
{
    return CartesianPosition(my.x, my.y + 1);
}

CartesianPosition NeighboringPositions::southwestern() const
{
    return CartesianPosition(my.x - 1, my.y + 1);
}

CartesianPosition NeighboringPositions::western() const
{
    return CartesianPosition(my.x - 1, my.y);
}

CartesianPosition NeighboringPositions::northwestern() const
{
    return CartesianPosition(my.x - 1, my.y - 1);
}

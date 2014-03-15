#include "NeighboringPositions.hpp"
using namespace ::ConwayGameOfLife;

NeighboringPositions::NeighboringPositions(Position position) :
    my(position)
{}

Position NeighboringPositions::northern() const
{
    return Position(my.x(), my.y() - 1);
}

Position NeighboringPositions::northeastern() const
{
    return Position(my.x() + 1, my.y() - 1);
}

Position NeighboringPositions::eastern() const
{
    return Position(my.x() + 1, my.y());
}

Position NeighboringPositions::southeastern() const
{
    return Position(my.x() + 1, my.y() + 1);
}

Position NeighboringPositions::southern() const
{
    return Position(my.x(), my.y() + 1);
}

Position NeighboringPositions::southwestern() const
{
    return Position(my.x() - 1, my.y() + 1);
}

Position NeighboringPositions::western() const
{
    return Position(my.x() - 1, my.y());
}

Position NeighboringPositions::northwestern() const
{
    return Position(my.x() - 1, my.y() - 1);
}

std::array<Position, 8> NeighboringPositions::iterator() const {
    return {{ northern(),
              northeastern(),
              eastern(),
              southeastern(),
              southern(),
              southwestern(),
              western(),
              northwestern() }};
}

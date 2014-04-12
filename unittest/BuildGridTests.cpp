#include "gtest/gtest.h"

#include "BuildGrid.hpp"
using namespace ::ConwayGameOfLife;

TEST(BuildGridTests, grid_is_not_finished_when_initialized)
{
    ASSERT_FALSE(BuildGrid::OfSize(4).finished());
}

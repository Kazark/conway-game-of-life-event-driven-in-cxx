#include "gtest/gtest.h"

#include "Grid.hpp"
#include "Cell.hpp"
using namespace ::ConwayGameOfLife;

TEST(GridTests, grid_has_iterator)
{
    Grid objectUnderTest = std::vector<bool> { true, false, true, true };
    auto count(0);
    for (auto cell : objectUnderTest.iterator())
    {
        if (cell.isLiving)
        {
            count++;
        }
    }
    ASSERT_EQ(3, count);
}

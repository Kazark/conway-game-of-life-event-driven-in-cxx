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

TEST(GridTests, grids_of_different_sizes_are_not_equal)
{
    Grid grid1({true, false, true, true});
    Grid grid2({true});

    ASSERT_NE(grid1, grid2);
}

TEST(GridTests, grids_of_same_size_with_different_contents_are_not_equal)
{
    Grid grid1({true, false, true, true});
    Grid grid2({true, true, false, true});

    ASSERT_NE(grid1, grid2);
}

TEST(GridTests, grids_of_same_size_with_same_contents_are_equal)
{
    Grid grid1({true, true, false, true});
    Grid grid2({true, true, false, true});

    ASSERT_EQ(grid1, grid2);
}

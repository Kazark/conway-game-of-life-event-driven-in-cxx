#include "gtest/gtest.h"

#include "Grid.hpp"
using namespace ::ConwayGameOfLife;

TEST(GridTests, grid_has_iterator)
{
    Grid objectUnderTest = {{ true, false, true, true }};
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
    Grid grid2(FixedLengthArray<bool>{true});

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

TEST(GridTests, should_be_able_to_retrieve_the_cell_which_it_at_a_position)
{
    Grid grid1({true, true, false, true});

    auto cell = grid1.cellAt(Position(0, 1));

    ASSERT_FALSE(cell.isLiving);
}

TEST(GridTests, should_return_cell_with_is_living_set_to_false_if_it_is_out_of_bounds)
{
    Grid grid1({true, true, true, true});

    auto cell = grid1.cellAt(Position(3, 3));

    ASSERT_FALSE(cell.isLiving);
}

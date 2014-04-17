#include "gtest/gtest.h"

#include "FixedLengthArray.hpp"
using namespace ::ConwayGameOfLife;

TEST(FixedLengthArrayTests, default_constructor_initializes_length_to_zero)
{
    ASSERT_EQ(0, FixedLengthArray<bool>().length());
}

TEST(FixedLengthArrayTests, length_constructor_initializes_to_specified_length)
{
    ASSERT_EQ(2, FixedLengthArray<bool>(2).length());
}

TEST(FixedLengthArrayTests, initializer_list_constructor_initializes_length_and_items_properly)
{
    FixedLengthArray<bool> objectUnderTest = {false, true, false};
    bool f = false;
    bool t = true;
    EXPECT_EQ(3, objectUnderTest.length());
    EXPECT_EQ(f, objectUnderTest[0]);
    EXPECT_EQ(t, objectUnderTest[1]);
    EXPECT_EQ(f, objectUnderTest[2]);
}

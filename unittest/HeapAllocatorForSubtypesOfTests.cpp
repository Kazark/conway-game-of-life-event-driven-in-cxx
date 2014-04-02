#include "gtest/gtest.h"

#include "HeapAllocatorForSubtypesOf.hpp"
using namespace ::EventArchitecture;

TEST(HeapAllocatorForSubtypesOfTests, returns_null_for_type_unregistered)
{
    HeapAllocatorForSubtypesOf<int> objectUnderTest;

    ASSERT_EQ(nullptr, objectUnderTest.fromConstRef(2));
}

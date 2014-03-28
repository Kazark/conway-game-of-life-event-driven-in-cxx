#include "gtest/gtest.h"

#include "SingletonScope.hpp"
using namespace ::EventArchitecture;

#include "ReferenceTypesForTesting.hpp"

TEST(SingletonScopeTests, attempt_to_get_type_when_container_is_empty_returns_nulltpr)
{
    ASSERT_EQ(nullptr, SingletonScope().getInstanceOf<SingletonScope>());
}

TEST(SingletonScopeTests, attempt_to_get_type_for_which_no_instance_has_been_saved_returns_nullptr)
{
    SingletonScope scope;
    scope.saveInstance(new XXX(5));
    ASSERT_EQ(nullptr, scope.getInstanceOf<YYY>());
}


TEST(SingletonScopeTests, returns_saved_instance)
{
    SingletonScope scope;
    scope.saveInstance(new XXX(5));
    ASSERT_EQ(5, scope.getInstanceOf<XXX>()->x);
}

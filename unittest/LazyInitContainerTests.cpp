#include "gtest/gtest.h"

#include "LazyInitContainer.hpp"
#include "Inject.hpp"
using namespace ::EventArchitecture;

#include "ReferenceTypesForTesting.hpp"

#include <stdexcept>

TEST(LazyInitContainerTests, returns_nullptr_when_no_injector_registered) {
    ASSERT_THROW(LazyInitContainer().getInstanceOf<ZZZ>(), std::out_of_range);
}

TEST(LazyInitContainerTests, does_not_return_nullptr_when_injector_registered) {
    LazyInitContainer objectUnderTest;
    objectUnderTest.registerInjector<XXX>([](LazyInitContainer&) { return new XXX(2); });
    objectUnderTest.registerInjector<YYY>(Inject<>::Into<YYY>);
    objectUnderTest.registerInjector<ZZZ>(Inject<XXX, YYY>::Into<ZZZ>);
    ASSERT_NO_THROW(objectUnderTest.getInstanceOf<ZZZ>());
}

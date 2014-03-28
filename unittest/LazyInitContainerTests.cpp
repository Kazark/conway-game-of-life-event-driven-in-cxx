#include "gtest/gtest.h"

#include "LazyInitContainer.hpp"
#include "Inject.hpp"
using namespace ::EventArchitecture;

#include "ReferenceTypesForTesting.hpp"

TEST(LazyInitContainerTests, returns_nullptr_when_no_injector_registered) {
    ASSERT_EQ(nullptr, LazyInitContainer().getInstanceOf<ZZZ>());
}

TEST(LazyInitContainerTests, does_not_return_nullptr_when_injector_registered) {
    LazyInitContainer objectUnderTest;
    objectUnderTest.registerInjector<XXX>([](LazyInitContainer&) { return new XXX(2); });
    objectUnderTest.registerInjector<YYY>(Inject<>::Into<YYY>);
    objectUnderTest.registerInjector<ZZZ>(Inject<XXX, YYY>::Into<ZZZ>);
    ASSERT_NE(nullptr, objectUnderTest.getInstanceOf<ZZZ>());
}

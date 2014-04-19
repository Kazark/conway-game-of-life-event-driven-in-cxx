#include "gtest/gtest.h"

#include "PrintGeneration.hpp"
#include "OutputPlaintextCells.hpp"
using namespace ::ConwayGameOfLife;

#include <sstream>

struct PrintGenerationTests: public ::testing::Test
{
    PrintGenerationTests() :
        stringBuilder(),
        outputter(stringBuilder),
        objectUnderTest(outputter)
    {}

    std::stringstream stringBuilder;
    OutputPlaintextCells outputter;
    PrintGeneration objectUnderTest;
};

TEST_F(PrintGenerationTests, smoke_test)
{
    objectUnderTest.handle(GenerationCompleted {
        true, false, true,
        false, true, false,
        true, false, false
    });

    ASSERT_EQ("O.O\n.O.\nO..\n", stringBuilder.str());
}

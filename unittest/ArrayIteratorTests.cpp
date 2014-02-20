#include "gtest/gtest.h"

// Code under test
#include "ArrayIterator.hpp"
using namespace ::ConwayGameOfLife;

#include <vector>

template<typename TElement>
class ArrayForTests {
public:
    ArrayForTests(TElement data[], int size) :
        data(data),
        size(size)
    {}
    TElement& operator[](int index) const {
        return data[index];
    }
    int length() const {
        return size;
    };
private:
    TElement* data;
    int size;
};

TEST(ArrayIteratorTests, can_iterate)
{
    std::vector<int> results;
    int array[3] = {1, 3, 2};
    ArrayIterator<int, ArrayForTests> iterator{ArrayForTests<int>{array, 3}};
    for (auto element : iterator) {
        results.push_back(element);
    }
    ASSERT_EQ(size_t(3), results.size());
    EXPECT_EQ(1, results[0]);
    EXPECT_EQ(3, results[1]);
    EXPECT_EQ(2, results[2]);
}

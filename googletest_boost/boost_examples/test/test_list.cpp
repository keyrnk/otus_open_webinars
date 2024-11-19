#define BOOST_TEST_MODULE example //allows test module initialization

#include "list.hpp"
#include <boost/test/included/unit_test.hpp> //single header variant
//only one translation unit

BOOST_AUTO_TEST_CASE(test_list)
{
    // Arrange
    otus::List<int> list;
    const size_t expectedZeroSize = 0;
    //Act
    const auto curSize = list.size();
    // Assert
    BOOST_TEST(curSize == expectedZeroSize);
    BOOST_TEST(expectedZeroSize == curSize);
    BOOST_TEST(list.empty());

    list.push_back(1);
    const size_t expectedSize = 1;

    BOOST_TEST(list.size() != expectedZeroSize);
    BOOST_TEST(list.size() == expectedSize);

    //uncomment to get a failure
    //BOOST_REQUIRE(list.size() < expectedSize);
    //BOOST_TEST(list.size() > expectedSize, "list size should be less than " << expectedSize);
}
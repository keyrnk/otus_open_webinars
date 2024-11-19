#define BOOST_TEST_MODULE fixture_example

#include "list.hpp"
#include <boost/test/included/unit_test.hpp>

//./test_fixture --log_level=message
struct ListFixture {
    ListFixture() //ctor is a setup method
    { 
        BOOST_TEST_MESSAGE( "setup fixture" ); 
        for (size_t i = 0; i < elementCount; ++i) 
            list.push_back(i);
    }

    ~ListFixture() //dtor is a teardown method
    { 
        BOOST_TEST_MESSAGE( "teardown fixture" ); 
        list.clear();
    }

    const size_t elementCount = 10;
    otus::List<size_t> list; //the same list instance for all test cases
};

BOOST_FIXTURE_TEST_SUITE(CheckSize, ListFixture)

  BOOST_AUTO_TEST_CASE(test_case1)
  {
    BOOST_TEST_MESSAGE("running test_case1");
    BOOST_CHECK_EQUAL(list.size(), elementCount);
  }

  BOOST_AUTO_TEST_CASE(test_case2)
  {
    BOOST_TEST_MESSAGE("running test_case2");
    const std::size_t expectedSize = 0;
    BOOST_CHECK_GE(list.size(), expectedSize);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(CheckDelete, ListFixture)

  //./test_fixture --log_level=test_suite
  BOOST_AUTO_TEST_CASE(test_case1, * boost::unit_test::disabled())
  {
    BOOST_TEST_MESSAGE("running test_case1");
    list.pop_back();
    BOOST_CHECK_NE(list.size(), elementCount);
    BOOST_CHECK_EQUAL(list.size(), elementCount - 1);
  }

BOOST_AUTO_TEST_SUITE_END()
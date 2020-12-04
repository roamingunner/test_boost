//  (C) Copyright Gennadiy Rozental 2005.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

// Boost.Test

// each test module could contain no more then one 'main' file with init function defined
// alternatively you could define init function yourself
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
namespace bt = boost::unit_test;

struct GlobalFixture {
  GlobalFixture() {
      BOOST_TEST_MESSAGE( "ctor fixture i=" << i );
  }
  void setup() {
      BOOST_TEST_MESSAGE( "setup fixture i=" << i );
      i++;
  }
  void teardown() {
      BOOST_TEST_MESSAGE( "teardown fixture i=" << i );
      i += 2;
  }
  ~GlobalFixture() {
      BOOST_TEST_MESSAGE( "dtor fixture i=" << i );
  }
  static int i;
};
int GlobalFixture::i = 0;

BOOST_TEST_GLOBAL_FIXTURE(GlobalFixture);

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE(suite)

// most frequently you implement test cases as a free functions with automatic registration
BOOST_AUTO_TEST_CASE(basic_assertion_api)
{
    //omit custom message in test log /report
    BOOST_TEST_MESSAGE("this is assertion_api test.");

    // reports 'error in "test1": test 2 == 1 failed' and test continue
    BOOST_TEST(2 == 1);
    // the same as BOOST_TEST. 
    BOOST_TEST_CHECK(2 == 1);

    // reports 'warn in "test1": test 2 == 1 warn' and test continue
    BOOST_TEST_WARN(3 == 1);    

    // reports 'error in "test1": test 2 == 1 failed' and test aborts
    //BOOST_TEST_REQUIRE(4 == 1); 
}

//____________________________________________________________________________//

struct F {
    F() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
    ~F()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }

    int i;
};

BOOST_FIXTURE_TEST_CASE( test_fixture1, F )
{
    // you have direct access to non-private members of fixture structure
    BOOST_TEST( i == 0 );
}

//____________________________________________________________________________//

// you could have any number of test cases with the same fixture
BOOST_FIXTURE_TEST_CASE( test_fixture2, F, * bt::depends_on("suite/test_fixture1") )
{
    BOOST_TEST( i == 2 );
    BOOST_TEST( i == 0 );
}

BOOST_AUTO_TEST_SUITE_END()

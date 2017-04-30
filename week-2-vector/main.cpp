#include <iostream>
#include <cstring>
#include "vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE( "constructor, two_parameters" ){
   vector v( 1, 2 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(1.2)" );
}

TEST_CASE( "add vector to vector, + operator" ){
   vector v( 1, 2 );
   REQUIRE( v + vector(2,3) == vector(3,5) );     
}

TEST_CASE( "add vector to vector, += operator" ){
   vector v( 1, 2 );
   v += vector(2,3);
   REQUIRE( v == vector(3,5) );     
}

TEST_CASE( "multiply vector with int, * operator" ){
   vector v( 1, 2 );
   REQUIRE( v * 3 == vector(3,6) );     
}

TEST_CASE( "multiply int with vector, * operator" ){
   vector v( 1, 2 );
   REQUIRE( 3 * v == vector(3,6) );     
}

TEST_CASE( "multiply vector with int, *= operator" ){
   vector v( 1, 2 );
   v *= 3;
   REQUIRE( v == vector(3,6) );     
}
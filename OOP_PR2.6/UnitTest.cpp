#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "RightAngled.cpp"
#include "RightAngled.hpp"

TEST_CASE( "Arguments initialized") {
    RightAngled::Triangle t1(3, 4, 5);
    RightAngled::Triangle t2(5, 5, 5);
    RightAngled::Triangle t3(10, 8, 6);

    REQUIRE( t1.perimeter() == 12);
    REQUIRE( t2.perimeter() == 15);
    REQUIRE( t3.perimeter() == 24);
}

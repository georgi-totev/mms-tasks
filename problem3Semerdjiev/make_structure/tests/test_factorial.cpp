#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp" 

extern "C" {
#include "library.h"              
}

TEST_CASE("factorial works", "[factorial]") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(5) == 120);
} //asdasd
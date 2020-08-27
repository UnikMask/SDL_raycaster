#include <catch2/catch.hpp>
#include "libraycaster.h"

// Math tests
TEST_CASE("vectors can be used for simple vectorial arithmetics", "[int]")
{
	SECTION("Check if catch2 works")
	{
		REQUIRE(1 + 1 == 2);
	}
	SECTION ("Check if vector initialization works")
	{
		ivec* test_ptr = new ivec (0, 0);
	}
	ivec a (5, 5);
	SECTION("Vectors can be defined and manipulated")
	{
		int arr[2] = {7, 3};
		gvec_assign(&a, arr);
		ivec c (7, 3);
		REQUIRE(a.num_arr[0] == 7);
		REQUIRE(gvec_eq(a, c) == true);
	}
}

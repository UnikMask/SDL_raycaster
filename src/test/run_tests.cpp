#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "libraycaster.h"

// Math tests
TEST_CASE("vectors can be used for simple vectorial arithmetics", "[int]")
{
	SECTION ("Check if vector initialization and pointers work")
	{
		auto test_ptr = std::make_unique<ivec>(0, 0);
	}
	ivec a (5, 5);
	SECTION("Vectors can be defined and manipulated")
	{
		int arr[2] = {7, 3};
		gvec_assign(&a, arr);
		ivec c (7, 3);
		REQUIRE(gvec_eq(a, c) == true);
	}
	gvec<int> b (2, 4);
	SECTION("Vectors can do additions and substractions")
	{
		gvec<int> add = a + b; gvec<int> add_res (9, 7);
		gvec<int> sub = a - b; gvec<int> sub_res (5, -1);
		REQUIRE(add.num_arr[0] == 9);
		REQUIRE(gvec_eq(add, add_res) == true);
		REQUIRE(gvec_eq(sub, sub_res) == true);
	}
}

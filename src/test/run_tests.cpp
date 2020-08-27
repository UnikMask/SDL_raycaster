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
	ivec a (7, 3);
	SECTION("Vectors can be defined and manipulated")
	{
		int arr[2] = {5, 5};
		gvec_assign(&a, arr);
		ivec c (5, 5);
		REQUIRE(gvec_eq(a, c) == true);
	}
	gvec<int> b (2, 4);
	SECTION("Vectors can do additions and substractions")
	{
		gvec<int> add = a + b; gvec<int> add_res (9, 7);
		gvec<int> sub = a - b; gvec<int> sub_res (5, -1);
		REQUIRE(gvec_eq(add, add_res) == true);
		REQUIRE(gvec_eq(sub, sub_res) == true);
	}
	SECTION("Vectors can do scalar multiplication (dot product) and by-element multiplication")
	{
		gvec<int> bemult = gvec_bemult(a, b); gvec<int> bemult_res (14, 12); 
		int dot = a * b; int dot_res = 14 + 12;
		REQUIRE(gvec_eq(bemult, bemult_res) == true);
		REQUIRE(dot == dot_res);
	}
}

#include <catch2/catch.hpp>
#include "libraycaster.h"

TEST_CASE("Vectors can be used for simple vectorial arithmetics", "[vector]")
{
	SECTION("Integer vector arithmetics")
	{
		ivec a  = {3, 7}; ivec b  = {2, 21};
		// Testing vectors
		int add [2] = {5, 28}; // Addition vector
		int sub [2] = {1, -14}; // Substraction vector
		int mult [2] = {9, 21}; // Multiplication vector
		int bemult [2] = {6, 147}; // per-element multiplication vector
		int dot = 153; // Dot product
		REQUIRE(gvec_add(a, b) == true);
		// REQUIRE((a + b).num_arr == add);
		//REQUIRE((a - b).num_arr == sub);
		//REQUIRE(gvec_bemult(a, b).num_arr == bemult);
		//REQUIRE(a * b == dot);
		//REQUIRE((a * 3).num_arr == mult);
	}
}

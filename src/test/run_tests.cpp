#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "libraycaster.h"


// Math tests
TEMPLATE_TEST_CASE("vectors can be used for simple vectorial arithmetics", "[vector]", 
		int, double) {
	SECTION ("Check if vector initialization and pointers work") {
		auto test_ptr = std::make_unique<gvec<TestType>>(0, 0);
	}
	gvec<TestType> a (7, 3);
	SECTION("Vectors can be defined and manipulated") {
		TestType arr[2] = {5, 5};
		gvec_assign(&a, arr);
		gvec<TestType> c (5, 5);
		REQUIRE(gvec_eq(a, c) == true);
	}
	gvec<TestType> b (2, 4);
	SECTION("Vectors can do additions and substractions") {
		gvec<TestType> add = a + b; gvec<TestType> add_res (9, 7);
		gvec<TestType> sub = a - b; gvec<TestType> sub_res (5, -1);
		REQUIRE(gvec_eq(add, add_res) == true);
		REQUIRE(gvec_eq(sub, sub_res) == true);
	}
	SECTION("Vectors can do scalar multiplication (dot product) and by-element multiplication") {
		gvec<TestType> bemult = gvec_bemult(a, b); gvec<TestType> bemult_res (14, 12); 
		TestType dot = a * b; TestType dot_res = 14 + 12;
		REQUIRE(gvec_eq(bemult, bemult_res) == true);
		REQUIRE(dot == dot_res);
	}
}

TEMPLATE_TEST_CASE("Matrices can be used for simple matrix and vector arithmetics",
		"[gmat]", int, double) {
SECTION("Check if matrices can be initialized and gmat pointers work") {
auto test_ptr = std::make_unique<gmat<TestType>>(0,0,0,0);
REQUIRE(test_ptr);
gvec<TestType> a (0, 0);
gvec<TestType> b (0, 0);
auto ptr_construct_2 = std::make_unique<gmat<TestType>>(a, b);
REQUIRE(ptr_construct_2);
}
gmat<TestType> a (8, 5, 2, 9);
SECTION("Matrices can be modified") {
TestType new_arr[2][2] = {{5, 5},{5, 5}};
gmat_assign(&a, new_arr);
gmat<TestType> assign_res (5, 5, 5, 5);
REQUIRE(gmat_eq(a, assign_res));

}
gmat<TestType> b (3, 7, 12, 1);
SECTION("Matrices can be used for matrix additon and substraction") {
/* Define all needed vectors and matrices for testing */
TestType testconst = 3;
gmat<TestType> add_res (11, 12, 14, 10); gmat<TestType> add = a + b;
gmat<TestType> sub_res (5, -2, -10, 8); gmat<TestType> sub = a - b;
gmat<TestType> constadd_res (11, 8, 5, 12); gmat<TestType> constadd = a + testconst;
gmat<TestType> constsub_res (5, 2, -1, 6); gmat<TestType> constsub = a - testconst;

REQUIRE(gmat_eq(add, add_res));
REQUIRE(gmat_eq(sub, sub_res));
REQUIRE(gmat_eq(constadd, constadd_res));
REQUIRE(gmat_eq(constsub, constsub_res));
}
SECTION("Matrices can be used for scalar and per-element multiplication and arithmetics") {
gmat<TestType> matmat0_res (84, 61, 114, 23);
gmat<TestType> matmat0 = a * b;
gmat<TestType> matmat1_res (38, 78, 98, 69);
gmat<TestType> matmat1 = b * a;

gmat<TestType> bemult_res (24, 35, 24, 9);
gmat<TestType> bemult = gmat_bemult(a, b);

gvec<TestType> c (4, -2); // Initialize vector for rest of tests.
gvec<TestType> vecmat_res (22, -10);
gvec<TestType> vecmat = a * c;
gvec<TestType> matvec_res (28, 2);
gvec<TestType> matvec = c * a;

REQUIRE(matmat0.num_arr[0][1] == 61);
REQUIRE(gmat_eq(matmat0, matmat0_res));
REQUIRE(gmat_eq(matmat1, matmat1_res));
REQUIRE(gvec_eq(vecmat, vecmat_res));
REQUIRE(gvec_eq(matvec_res, matvec));
REQUIRE(gmat_eq(bemult, bemult_res));

}
}

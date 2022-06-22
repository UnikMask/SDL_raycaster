#define CATCH_CONFIG_MAIN
#include "libraycaster.h"
#include <catch2/catch.hpp>
#include <iostream>
#include <memory>

// Math tests
TEMPLATE_TEST_CASE("vectors can be used for simple vectorial arithmetics",
                   "[vector]", int, double) {
  SECTION("Check if vector initialization and pointers work") {
    auto test_ptr = std::make_unique<gvec<TestType>>(0, 0);
  }
  gvec<TestType> a(7, 3);
  SECTION("Vectors can be defined and manipulated") {
    std::vector<TestType> arr{5, 5};
    gvec_assign(&a, arr);
    gvec<TestType> c(5, 5);
    REQUIRE(gvec_eq(a, c) == true);
  }
  gvec<TestType> b(2, 4);
  SECTION("Vectors can do additions and substractions") {
    gvec<TestType> add = a + b;
    gvec<TestType> add_res(9, 7);
    gvec<TestType> sub = a - b;
    gvec<TestType> sub_res(5, -1);
    REQUIRE(gvec_eq(add, add_res) == true);
    REQUIRE(gvec_eq(sub, sub_res) == true);
  }
  SECTION("Vectors can do scalar multiplication (dot product) and by-element "
          "multiplication") {
    gvec<TestType> bemult = gvec_bemult(a, b);
    gvec<TestType> bemult_res(14, 12);
    TestType dot = a * b;
    TestType dot_res = 14 + 12;
    REQUIRE(gvec_eq(bemult, bemult_res) == true);
    REQUIRE(dot == dot_res);
  }
}

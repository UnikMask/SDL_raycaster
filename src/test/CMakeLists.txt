# CMakeList for tests

# List all include directories for testing
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

list(APPEND TESTING_INCLUDES ${INCLUDE_DIR})
list(APPEND TEST_SOURCES ${TEST_DIR}/run_tests.cpp
	${TEST_DIR}/math/math_tests.cpp)

add_executable(Tester ${TEST_SOURCES} )

target_include_directories(Tester PUBLIC ${INCLUDE_DIR} )
target_link_libraries(Tester PUBLIC raycaster)

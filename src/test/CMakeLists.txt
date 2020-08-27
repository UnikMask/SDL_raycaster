# CMakeList for tests

# List all include directories for testing
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

list(APPEND TESTING_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
	${INCLUDE_DIR}
	)

add_library(math_tests OBJECT math/math_tests.cpp)
target_include_directories(math_tests PUBLIC ${INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Tester run_tests.cpp
	$<TARGET_OBJECTS:math_tests>)

target_include_directories(Tester PUBLIC ${INCLUDE_DIR} )
add_dependencies(Tester raycaster)
target_link_libraries(Tester PUBLIC raycaster)

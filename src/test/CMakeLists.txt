# CMakeList for tests

# List all include directories for testing
list(APPEND TESTING_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/main/math 
	${CMAKE_SOURCE_DIR}/src/main)

add_executable(Tester run_tests.cpp)

target_include_directories(Tester PUBLIC TESTING_INCLUDES)
target_link_libraries(Tester raycaster)

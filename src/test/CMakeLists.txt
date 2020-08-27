# CMakeList for tests

# List all include directories for testing
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

list(APPEND TESTING_INCLUDES ${INCLUDE_DIR})

add_executable(Tester run_tests.cpp)

target_include_directories(Tester PUBLIC ${INCLUDE_DIR} )
target_link_libraries(Tester PUBLIC raycaster)

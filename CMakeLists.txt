Cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

# Get version from version text file
file(STRINGS version.txt VER_REG REGEX "^[0-9]+\\.[0-9]+\\.[0-9]+.*$"
	LIMIT_COUNT 1)

# Get description of the project
file(STRINGS desc.txt DESC_STR REGEX ".*$")
project(raycaster VERSION ${VER_REG} DESCRIPTION ${DESC_STR})

# Check for dependency libraries
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

# Add all main directories
set (INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
list(APPEND CMAKELIST_DIRS
	"${CMAKE_SOURCE_DIR}/src/main/")

# Call CMakeLists of all dirs and add created object files to list
add_subdirectory(${CMAKELIST_DIRS})

# Add include directories

# Add testing compilation
option(COMPILE_TEST "Compile tests? " OFF)
if(COMPILE_TEST)
	add_subdirectory("${PROJECT_SOURCE_DIR}/src/test")
	enable_testing()
endif()

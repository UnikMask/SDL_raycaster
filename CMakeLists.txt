Cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Get version from version text file
file(STRINGS version.txt VER_REG REGEX "^[0-9]+\\.[0-9]+\\.[0-9]+.*$"
	LIMIT_COUNT 1)

# Get description of the project
file(STRINGS desc.txt DESC_STR REGEX ".*$")
project(raycaster VERSION ${VER_REG} DESCRIPTION ${DESC_STR})

# Fetch SDL2 package files from github
if (NOT EXISTS "${CMAKE_SOURCE_DIR}/cmake/sdl2")
	execute_process( COMMAND mkdir ${CMAKE_SOURCE_DIR}/cmake )
	execute_process( COMMAND mkdir ${CMAKE_SOURCE_DIR}/cmake/sdl2 )
	execute_process(
	  COMMAND git clone "https://github.com/aminosbh/sdl2-cmake-modules.git"
	  ${CMAKE_SOURCE_DIR}/cmake/sdl2)
endif()

# Check for dependency libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Add all main directories
set (INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
list(APPEND CMAKELIST_DIRS
	"${CMAKE_SOURCE_DIR}/lib")

# Call CMakeLists of all dirs and add created object files to list
add_subdirectory(${CMAKELIST_DIRS})

# Add include directories

# Add testing compilation
option(COMPILE_TEST "Compile tests? " OFF)
if(COMPILE_TEST)
	add_subdirectory("${PROJECT_SOURCE_DIR}/tests")
	enable_testing()
endif()

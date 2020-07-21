Cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

# Get version from version text file
file(STRINGS version.txt VER_REG REGEX "^[0-9]+\\.[0-9]+\\.[0-9]+.*$"
	LIMIT_COUNT 1)

# Get description of the project
file(STRINGS desc.txt DESC_STR REGEX ".*\\$")
project(raycaster VERSION ${VER_REG} DESCRIPTION ${DESC_STR})

# Add all main directories
list(APPEND TOTAL_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main/math")

# Call CMakeLists of all dirs and add created object files to list
add_subdirectory(${TOTAL_DIRS})

# Add include directories
add_library(raycaster SHARED $<TARGET_OBJECTS:PlaneMaths>)
target_include_directories(raycaster PUBLIC ${TOTAL_DIRS})

# Add testing compilation
option(COMPILE_TEST "Compile tests? " OFF)
if(COMPILE_TEST)
	add_subdirectory("${PROJECT_SOURCE_DIR}/src/test")
endif()


# Install instructions
install(TARGETS raycaster DESTINATION lib)

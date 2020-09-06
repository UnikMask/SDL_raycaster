set (INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set (MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
list (APPEND MAP_SOURCES ${MAIN_DIR}/map/map.cpp)
list (APPEND PROJECT_SOURCES
	${MATH_SOURCES})

add_library(raycaster SHARED ${MAP_SOURCES})
target_include_directories(raycaster PUBLIC ${INCLUDE_DIR})
install (TARGETS raycaster 
	ARCHIVE DESTINATION lib/
	LIBRARY DESTINATION lib 
	COMPONENT library)

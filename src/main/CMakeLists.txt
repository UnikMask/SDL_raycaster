set (INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set (MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
list (APPEND MATH_SOURCES
	${MAIN_DIR}/math/gmat.cpp)
list (APPEND PROJECT_SOURCES
	${MATH_SOURCES})

add_library(raycaster SHARED ${MATH_SOURCES})
target_include_directories(raycaster PUBLIC ${INCLUDE_DIR})
install (TARGETS raycaster 
	ARCHIVE DESTINATION lib/
	LIBRARY DESTINATION lib 
	COMPONENT library)

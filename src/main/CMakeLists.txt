set (INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set (MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
list (APPEND MATH_SOURCES
	${MAIN_DIR}/math/gvec.cpp
	${MAIN_DIR}/math/gmat.cpp
	${INCLUDE_DIR}/gvec.h
	${INCLUDE_DIR}/gmat.h)
list (APPEND PROJECT_SOURCES
	${MATH_SOURCES})

add_library(raycaster SHARED ${PROJECT_SOURCES})
target_include_directories(raycaster PUBLIC ${INCLUDE_DIR})
install (TARGETS raycaster ARCHIVE DESTINATION lib/)

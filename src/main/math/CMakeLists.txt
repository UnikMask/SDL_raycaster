add_library(PlaneMaths OBJECT gmat.cpp gvec.cpp)
target_include_directories(PlaneMaths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES gmat.h gvec.h DESTINATION include/raycaster/math)

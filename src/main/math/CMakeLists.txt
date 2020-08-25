add_library(PlaneMaths OBJECT gmat.cpp gvec.cpp)
target_include_directories(PlaneMaths PUBLIC ${CMAKE_SOURCE_DIR}/include)

install(FILES gmat.h gvec.h DESTINATION include/raycaster/math)

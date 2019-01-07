cmake_minimum_required(VERSION 2.8)

PROJECT(ParametricObjects)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(${PROJECT_NAME} ParametricObjects.cxx )

target_link_libraries(ParametricObjects ${VTK_LIBRARIES})

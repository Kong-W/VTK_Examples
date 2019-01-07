cmake_minimum_required(VERSION 2.8)

PROJECT(StructuredPointsReader)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(${PROJECT_NAME} StructuredPointsReader.cxx )

target_link_libraries(StructuredPointsReader ${VTK_LIBRARIES})

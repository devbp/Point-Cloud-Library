cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(PointCloud)

find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set( SOURCES display.cpp segmentation.cpp)
#add library PointCloud

add_library( DISPLAY SHARED ${SOURCES} )
target_link_libraries(DISPLAY ${PCL_LIBRARIES})
add_executable (main main.cpp)
#target_link_libraries (PointCloud ${PCL_LIBRARIES})
target_link_libraries(main DISPLAY)


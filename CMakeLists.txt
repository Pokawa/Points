cmake_minimum_required(VERSION 3.9)
project(Points)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME "Points")

add_executable(${EXECUTABLE_NAME} main.cpp Point.cpp Point.h Points.cpp Points.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

cmake_minimum_required(VERSION 3.23)
project(sharedCeasarUsage)

set(CMAKE_CXX_STANDARD 14)

add_executable(sharedCeasarUsage main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/caesarLib)
target_link_libraries(sharedCeasarUsage ${PROJECT_SOURCE_DIR}/caesarLib/libsharedCaesar.dylib)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE Release)
project(pool-test)

IF (${CMAKE_COMPILER_IS_GNUCXX})
    SET(CMAKE_CXX_FLAGS "-std=c++0x")
ENDIF ()

include_directories(
    ${CMAKE_SOURCE_DIR}/../
)

set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_SOURCE_DIR}/")

add_executable(test
  gtest/gtest-all.cc
  gtest/gtest.h
  test.cpp
)

target_link_libraries(test pthread)
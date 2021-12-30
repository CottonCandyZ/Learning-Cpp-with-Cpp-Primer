cmake_minimum_required(VERSION 3.0.0)
project(C++_Primer)

include(CTest)
enable_testing()

# 第一章
add_executable(1-1 01-start/1-1-main.cpp)
add_executable(1-3 01-start/1-3-Hello.cpp)
add_executable(1-4 01-start/1-4-add.cpp)
add_executable(1-7 01-start/1-7-wrong-commit.cpp)
add_executable(1-8 01-start/1-8-fix-commit.cpp)
add_executable(1-9 01-start/1-9.cpp)
add_executable(1-10 01-start/1-10.cpp)
add_executable(1-11 01-start/1-11.cpp)
add_executable(1-12 01-start/1-12.cpp)
add_executable(1-13 01-start/1-13.cpp)
add_executable(1-16 01-start/1-16.cpp)
add_executable(1-18 01-start/1-18.cpp)
add_executable(1-19 01-start/1-19.cpp)
add_executable(1-20 01-start/1-20.cpp 01-start/Sales_item.h)
add_executable(1-21 01-start/1-21.cpp 01-start/Sales_item.h)
add_executable(1-22 01-start/1-22.cpp 01-start/Sales_item.h)
add_executable(1-23 01-start/1-23.cpp 01-start/Sales_item.h)
add_executable(1-25 01-start/1-25.cpp 01-start/Sales_item.h)

# 第二章



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

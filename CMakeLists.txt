cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(C++_Primer)

include(CTest)
enable_testing()

# 第 1 章
add_executable(01-01 01-start/1.cpp)
add_executable(01-02 01-start/2.cpp)
add_executable(01-03 01-start/3.cpp)
add_executable(01-04 01-start/4.cpp)
add_executable(01-05 01-start/5.cpp)
add_executable(01-07 01-start/7.cpp)
add_executable(01-08 01-start/8.cpp)
add_executable(01-09 01-start/9.cpp)
add_executable(01-10 01-start/10.cpp)
add_executable(01-11 01-start/11.cpp)
add_executable(01-12 01-start/12.cpp)
add_executable(01-13 01-start/13.cpp)
add_executable(01-16 01-start/16.cpp)
add_executable(01-18 01-start/18.cpp)
add_executable(01-19 01-start/19.cpp)
add_executable(01-20 01-start/20.cpp 01-start/Sales_item.h)
add_executable(01-21 01-start/21.cpp 01-start/Sales_item.h)
add_executable(01-22 01-start/22.cpp 01-start/Sales_item.h)
add_executable(01-23 01-start/23.cpp 01-start/Sales_item.h)
add_executable(01-25 01-start/25.cpp 01-start/Sales_item.h)

# 第 2 章
add_executable(02-04 02-Variables-and-Basic-Types/4.cpp)
add_executable(02-08 02-Variables-and-Basic-Types/8.cpp)
add_executable(02-10 02-Variables-and-Basic-Types/10.cpp)
add_executable(02-18 02-Variables-and-Basic-Types/18.cpp)
add_executable(02-28 02-Variables-and-Basic-Types/28.cpp)
add_executable(02-29 02-Variables-and-Basic-Types/29.cpp)
add_executable(02-30 02-Variables-and-Basic-Types/30.cpp)
add_executable(02-31 02-Variables-and-Basic-Types/31.cpp)
add_executable(02-32 02-Variables-and-Basic-Types/32.cpp)
add_executable(02-33 02-Variables-and-Basic-Types/33.cpp)
add_executable(02-35 02-Variables-and-Basic-Types/35.cpp)
add_executable(02-36 02-Variables-and-Basic-Types/36.cpp)
add_executable(02-37 02-Variables-and-Basic-Types/37.cpp)
add_executable(02-39 02-Variables-and-Basic-Types/39.cpp)
add_executable(02-40 02-Variables-and-Basic-Types/40.cpp)
add_executable(02-41 02-Variables-and-Basic-Types/41.cpp)

# 第 3 章
add_executable(03-01 03-Strings-Vectors-Arrays/1.cpp)
add_executable(03-02 03-Strings-Vectors-Arrays/2.cpp)
add_executable(03-04 03-Strings-Vectors-Arrays/4.cpp)
add_executable(03-05 03-Strings-Vectors-Arrays/5.cpp)
add_executable(03-06 03-Strings-Vectors-Arrays/6.cpp)
add_executable(03-07 03-Strings-Vectors-Arrays/7.cpp)
add_executable(03-08 03-Strings-Vectors-Arrays/8.cpp)
add_executable(03-10 03-Strings-Vectors-Arrays/10.cpp)
add_executable(03-12 03-Strings-Vectors-Arrays/12.cpp)
add_executable(03-13 03-Strings-Vectors-Arrays/13.cpp)
add_executable(03-14 03-Strings-Vectors-Arrays/14.cpp)
add_executable(03-15 03-Strings-Vectors-Arrays/15.cpp)
add_executable(03-16 03-Strings-Vectors-Arrays/16.cpp)
add_executable(03-18 03-Strings-Vectors-Arrays/18.cpp)
add_executable(03-19 03-Strings-Vectors-Arrays/19.cpp)
add_executable(03-20 03-Strings-Vectors-Arrays/20.cpp)
add_executable(03-21 03-Strings-Vectors-Arrays/21.cpp)
add_executable(03-22 03-Strings-Vectors-Arrays/22.cpp)
add_executable(03-23 03-Strings-Vectors-Arrays/23.cpp)
add_executable(03-24 03-Strings-Vectors-Arrays/24.cpp)
add_executable(03-25 03-Strings-Vectors-Arrays/25.cpp)
add_executable(03-27 03-Strings-Vectors-Arrays/27.cpp)
add_executable(03-28 03-Strings-Vectors-Arrays/28.cpp)
add_executable(03-30 03-Strings-Vectors-Arrays/30.cpp)
add_executable(03-31 03-Strings-Vectors-Arrays/31.cpp)
add_executable(03-32 03-Strings-Vectors-Arrays/32.cpp)
add_executable(03-35 03-Strings-Vectors-Arrays/35.cpp)
add_executable(03-36 03-Strings-Vectors-Arrays/36.cpp)
add_executable(03-37 03-Strings-Vectors-Arrays/37.cpp)
add_executable(03-39 03-Strings-Vectors-Arrays/39.cpp)
add_executable(03-40 03-Strings-Vectors-Arrays/40.cpp)
add_executable(03-41 03-Strings-Vectors-Arrays/41.cpp)
add_executable(03-42 03-Strings-Vectors-Arrays/42.cpp)
add_executable(03-43 03-Strings-Vectors-Arrays/43.cpp)
add_executable(03-44 03-Strings-Vectors-Arrays/44.cpp)
add_executable(03-45 03-Strings-Vectors-Arrays/45.cpp)

# 第 4 章
add_executable(04-01 04-Expressions/1.cpp)
add_executable(04-02 04-Expressions/2.cpp)
add_executable(04-04 04-Expressions/4.cpp)
add_executable(04-05 04-Expressions/5.cpp)
add_executable(04-06 04-Expressions/6.cpp)
add_executable(04-07 04-Expressions/7.cpp)
add_executable(04-10 04-Expressions/10.cpp)
add_executable(04-11 04-Expressions/11.cpp)
add_executable(04-13 04-Expressions/13.cpp)
add_executable(04-21 04-Expressions/21.cpp)
add_executable(04-22 04-Expressions/22.cpp)
add_executable(04-25 04-Expressions/25.cpp)
add_executable(04-27 04-Expressions/27.cpp)
add_executable(04-28 04-Expressions/28.cpp)
add_executable(04-29 04-Expressions/29.cpp)

# 第 5 章
add_executable(05-05 05-Statements/5.cpp)
add_executable(05-06 05-Statements/6.cpp)
add_executable(05-09 05-Statements/9.cpp)
add_executable(05-10 05-Statements/10.cpp)
add_executable(05-11 05-Statements/11.cpp)
add_executable(05-12 05-Statements/12.cpp)
add_executable(05-14 05-Statements/14.cpp)
# add_executable(05-15 05-Statements/15.cpp)
add_executable(05-16 05-Statements/16.cpp)
add_executable(05-19 05-Statements/19.cpp)
add_executable(05-20 05-Statements/20.cpp)
add_executable(05-21 05-Statements/21.cpp)
add_executable(05-23 05-Statements/23.cpp)
add_executable(05-24 05-Statements/24.cpp)
add_executable(05-25 05-Statements/25.cpp)

# 第 6 章
add_executable(06-03 06-Functions/3.cpp)
add_executable(06-04 06-Functions/4.cpp)
add_executable(06-05 06-Functions/5.cpp)
add_executable(06-07 06-Functions/7.cpp)
add_executable(06-09 06-Functions/9/fact.cpp 06-Functions/9/factMain.cpp)
add_executable(06-10 06-Functions/10.cpp)
add_executable(06-11 06-Functions/11.cpp)
add_executable(06-12 06-Functions/12.cpp)
add_executable(06-17 06-Functions/17.cpp)
add_executable(06-21 06-Functions/21.cpp)
add_executable(06-22 06-Functions/22.cpp)
add_executable(06-23 06-Functions/23.cpp)
add_executable(06-25 06-Functions/25.cpp)
add_executable(06-26 06-Functions/26.cpp)
add_executable(06-27 06-Functions/27.cpp)
add_executable(06-30 06-Functions/30.cpp)
add_executable(06-33 06-Functions/33.cpp)
add_executable(06-42 06-Functions/42.cpp)
add_executable(06-47 06-Functions/47.cpp)
add_executable(06-51 06-Functions/51.cpp)
add_executable(06-55 06-Functions/55.cpp)
add_executable(06-56 06-Functions/56.cpp)

# 第 7 章
add_executable(07-01 07-Classes/1.cpp 02-Variables-and-Basic-Types/Sales_data.h)
add_executable(07-03 07-Classes/3.cpp 07-Classes/Sales_data_1.h)
add_executable(07-07 07-Classes/7.cpp 07-Classes/Sales_data_2.h)
add_executable(07-11 07-Classes/11.cpp 07-Classes/Sales_data_3.h)
add_executable(07-13 07-Classes/13.cpp 07-Classes/Sales_data_4.h)
add_executable(07-27 07-Classes/27.cpp 07-Classes/Screen_2.h)
add_executable(07-29 07-Classes/29.cpp 07-Classes/Screen_2_e.h)
add_executable(07-41 07-Classes/41.cpp 07-Classes/Sales_data_7.h)

# 第 8 章
add_executable(08-02 08-The-IO-Library/2.cpp)
add_executable(08-04 08-The-IO-Library/4.cpp)
add_executable(08-05 08-The-IO-Library/5.cpp)
add_executable(08-06 08-The-IO-Library/6.cpp)
add_executable(08-07 08-The-IO-Library/7.cpp)
add_executable(08-08 08-The-IO-Library/8.cpp)
add_executable(08-09 08-The-IO-Library/9.cpp)
add_executable(08-10 08-The-IO-Library/10.cpp)
add_executable(08-11 08-The-IO-Library/11.cpp)
add_executable(08-13 08-The-IO-Library/13.cpp)

# 第 9 章
add_executable(09-04 09-Sequential-Containers/4.cpp)
add_executable(09-05 09-Sequential-Containers/5.cpp)
add_executable(09-13 09-Sequential-Containers/13.cpp)
add_executable(09-14 09-Sequential-Containers/14.cpp)
add_executable(09-15 09-Sequential-Containers/15.cpp)
add_executable(09-16 09-Sequential-Containers/16.cpp)
add_executable(09-18 09-Sequential-Containers/18.cpp)
add_executable(09-19 09-Sequential-Containers/19.cpp)
add_executable(09-20 09-Sequential-Containers/20.cpp)
add_executable(09-24 09-Sequential-Containers/24.cpp)
add_executable(09-26 09-Sequential-Containers/26.cpp)
add_executable(09-27 09-Sequential-Containers/27.cpp)
add_executable(09-28 09-Sequential-Containers/28.cpp)
add_executable(09-31_list 09-Sequential-Containers/31_list.cpp)
add_executable(09-31_forward_list 09-Sequential-Containers/31_forward_list.cpp)
add_executable(09-38 09-Sequential-Containers/38.cpp)
add_executable(09-41 09-Sequential-Containers/41.cpp)
add_executable(09-43 09-Sequential-Containers/43.cpp)
add_executable(09-44 09-Sequential-Containers/44.cpp)
add_executable(09-45 09-Sequential-Containers/45.cpp)
add_executable(09-46 09-Sequential-Containers/46.cpp)
add_executable(09-47_find_first_of 09-Sequential-Containers/47_find_first_of.cpp)
add_executable(09-47_find_first_not_of 09-Sequential-Containers/47_find_first_not_of.cpp)
add_executable(09-49 09-Sequential-Containers/49.cpp)
add_executable(09-50 09-Sequential-Containers/50.cpp)
add_executable(09-51 09-Sequential-Containers/51.cpp 09-Sequential-Containers/51.h)
add_executable(09-52 09-Sequential-Containers/52.cpp)

# 第 10 章
add_executable(10-01 10-Generic-Algorithms/1.cpp)
add_executable(10-02 10-Generic-Algorithms/2.cpp)
add_executable(10-03 10-Generic-Algorithms/3.cpp)
add_executable(10-06 10-Generic-Algorithms/6.cpp)
add_executable(10-07 10-Generic-Algorithms/7.cpp)
add_executable(10-09 10-Generic-Algorithms/9.cpp)
add_executable(10-11 10-Generic-Algorithms/11.cpp)
add_executable(10-12 10-Generic-Algorithms/12.cpp 07-Classes/Sales_data_6.h)
add_executable(10-13 10-Generic-Algorithms/13.cpp)
add_executable(10-16 10-Generic-Algorithms/16.cpp)
add_executable(10-17 10-Generic-Algorithms/17.cpp)
add_executable(10-18 10-Generic-Algorithms/18.cpp)
add_executable(10-19 10-Generic-Algorithms/19.cpp)
add_executable(10-20 10-Generic-Algorithms/20.cpp)
add_executable(10-21 10-Generic-Algorithms/21.cpp)
add_executable(10-22 10-Generic-Algorithms/22.cpp)
add_executable(10-24 10-Generic-Algorithms/24.cpp)
add_executable(10-25 10-Generic-Algorithms/25.cpp)
add_executable(10-27 10-Generic-Algorithms/27.cpp)
add_executable(10-28 10-Generic-Algorithms/28.cpp)
add_executable(10-29 10-Generic-Algorithms/29.cpp)
add_executable(10-30 10-Generic-Algorithms/30.cpp)
add_executable(10-31 10-Generic-Algorithms/31.cpp)
add_executable(10-32 10-Generic-Algorithms/32.cpp)
add_executable(10-33 10-Generic-Algorithms/33.cpp)
add_executable(10-34 10-Generic-Algorithms/34.cpp)
add_executable(10-35 10-Generic-Algorithms/35.cpp)
add_executable(10-36 10-Generic-Algorithms/36.cpp)
add_executable(10-37 10-Generic-Algorithms/37.cpp)
add_executable(10-42 10-Generic-Algorithms/42.cpp)

# 第 11 章
add_executable(11-03 11-Associative-Containers/3.cpp)
add_executable(11-04 11-Associative-Containers/4.cpp)
add_executable(11-07 11-Associative-Containers/7.cpp)
add_executable(11-08 11-Associative-Containers/8.cpp)
add_executable(11-10 11-Associative-Containers/10.cpp)
add_executable(11-12 11-Associative-Containers/12.cpp)
add_executable(11-14 11-Associative-Containers/14.cpp)
add_executable(11-16 11-Associative-Containers/16.cpp)
add_executable(11-20 11-Associative-Containers/20.cpp)
add_executable(11-23 11-Associative-Containers/23.cpp)
add_executable(11-24 11-Associative-Containers/24.cpp)
add_executable(11-31 11-Associative-Containers/31.cpp)
add_executable(11-32 11-Associative-Containers/32.cpp)
add_executable(11-33 11-Associative-Containers/33.cpp)
add_executable(11-38_word_count 11-Associative-Containers/38_word_count.cpp)
add_executable(11-38_word_transform 11-Associative-Containers/38_word_transform.cpp)

# 第 12 章
add_executable(12-03 12-Dynamic-Memory/3.cpp)
add_executable(12-06 12-Dynamic-Memory/6.cpp)
add_executable(12-07 12-Dynamic-Memory/7.cpp)
add_executable(12-10 12-Dynamic-Memory/10.cpp)
add_executable(12-11 12-Dynamic-Memory/11.cpp)
add_executable(12-13 12-Dynamic-Memory/13.cpp)
add_executable(12-14 12-Dynamic-Memory/14.cpp)
add_executable(12-15 12-Dynamic-Memory/15.cpp)
add_executable(12-16 12-Dynamic-Memory/16.cpp)
add_executable(12-17 12-Dynamic-Memory/17.cpp)
add_executable(12-20 12-Dynamic-Memory/20.cpp)
add_executable(12-23 12-Dynamic-Memory/23.cpp)
add_executable(12-24 12-Dynamic-Memory/24.cpp)
add_executable(12-26 12-Dynamic-Memory/26.cpp)
add_executable(12-28 12-Dynamic-Memory/28.cpp)
add_executable(12-30 12-Dynamic-Memory/30.cpp)
add_executable(12-32 12-Dynamic-Memory/32.cpp)

# 第 13 章
add_executable(13-13 13-Copy-Control/13.cpp)
add_executable(13-17 13-Copy-Control/17.cpp)
add_executable(13-31 13-Copy-Control/31.cpp)
add_executable(13-42 13-Copy-Control/42.cpp)
add_executable(13-44 13-Copy-Control/44.cpp)
add_executable(13-48 13-Copy-Control/48.cpp)
add_executable(13-50 13-Copy-Control/50.cpp)
add_executable(13-58 13-Copy-Control/58.cpp)

# 第 14 章
add_executable(14-07 14-Overloaded-Operations-and-Conversions/7.cpp)
add_executable(14-08 14-Overloaded-Operations-and-Conversions/8.cpp)
add_executable(14-36 14-Overloaded-Operations-and-Conversions/36.cpp)
add_executable(14-37 14-Overloaded-Operations-and-Conversions/37.cpp)
add_executable(14-38 14-Overloaded-Operations-and-Conversions/38.cpp)
add_executable(14-39 14-Overloaded-Operations-and-Conversions/39.cpp)
add_executable(14-40 14-Overloaded-Operations-and-Conversions/40.cpp)
add_executable(14-43 14-Overloaded-Operations-and-Conversions/43.cpp)
add_executable(14-44 14-Overloaded-Operations-and-Conversions/44.cpp)
add_executable(14-45 14-Overloaded-Operations-and-Conversions/45.cpp)
add_executable(14-51 14-Overloaded-Operations-and-Conversions/51.cpp)
add_executable(14-52 14-Overloaded-Operations-and-Conversions/52.cpp)
add_executable(14-53 14-Overloaded-Operations-and-Conversions/53.cpp)

# 第 15 章
add_executable(15-06 15-Object-Oriented-Programming/6.cpp)
add_executable(15-21 15-Object-Oriented-Programming/21.cpp)
add_executable(15-23 15-Object-Oriented-Programming/23.cpp)
add_executable(15-26 15-Object-Oriented-Programming/26.cpp)
add_executable(15-28 15-Object-Oriented-Programming/28.cpp)
add_executable(15-29 15-Object-Oriented-Programming/29.cpp)
add_executable(15-30 15-Object-Oriented-Programming/30.cpp)
add_executable(15-36 15-Object-Oriented-Programming/36/36.cpp)
add_executable(15-39 15-Object-Oriented-Programming/15.9/39.cpp)
add_executable(15-41 15-Object-Oriented-Programming/41/41.cpp)

# 第 16 章
add_executable(16-02 16-Templates-and-Generic-Programming/2.cpp)
add_executable(16-03 16-Templates-and-Generic-Programming/3.cpp)
add_executable(16-04 16-Templates-and-Generic-Programming/4.cpp)
add_executable(16-05 16-Templates-and-Generic-Programming/5.cpp)
add_executable(16-06 16-Templates-and-Generic-Programming/6.cpp)
add_executable(16-07 16-Templates-and-Generic-Programming/7.cpp)
add_executable(16-14 16-Templates-and-Generic-Programming/14.cpp)
add_executable(16-15 16-Templates-and-Generic-Programming/15.cpp)
add_executable(16-19 16-Templates-and-Generic-Programming/19.cpp)
add_executable(16-20 16-Templates-and-Generic-Programming/20.cpp)
add_executable(16-23 16-Templates-and-Generic-Programming/23.cpp)
add_executable(16-28 16-Templates-and-Generic-Programming/28.cpp)
add_executable(16-30 16-Templates-and-Generic-Programming/30.cpp)
add_executable(16-47 16-Templates-and-Generic-Programming/47.cpp)
add_executable(16-50 16-Templates-and-Generic-Programming/50.cpp)
add_executable(16-52 16-Templates-and-Generic-Programming/52.cpp)
add_executable(16-53 16-Templates-and-Generic-Programming/53.cpp)
add_executable(16-54 16-Templates-and-Generic-Programming/54.cpp)
add_executable(16-55 16-Templates-and-Generic-Programming/55.cpp)
add_executable(16-56 16-Templates-and-Generic-Programming/56.cpp)
add_executable(16-59 16-Templates-and-Generic-Programming/59.cpp)
add_executable(16-61 16-Templates-and-Generic-Programming/61.cpp)
add_executable(16-62 16-Templates-and-Generic-Programming/62.cpp)
add_executable(16-63 16-Templates-and-Generic-Programming/63.cpp)
add_executable(16-64 16-Templates-and-Generic-Programming/64.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

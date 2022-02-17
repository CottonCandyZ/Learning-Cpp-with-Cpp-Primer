# 第 8 章 IO 库

## 1

```c++
istream &input(istream &is) {
    std::string buffer; // 使用 string 构建一个缓冲
    while (is >> buffer) {
        std::cout << buffer << std::endl;
    }
    is.clear();
    return is;
}
```

## [2](2.cpp)

## 3

遇到不可恢复的错误（`badbit`），可恢复错误（`failbit` 和 `eofbit`）：错误字符（类型不匹配）、文件结束。同 `!fail()`。

## [4](4.cpp)

## [5](5.cpp)

## [6](6.cpp)

## [7](7.cpp)

## [8](8.cpp)

## [9](9.cpp)

## [10](10.cpp)

## [11](11.cpp)

## 12

仅仅作为一个集合类使用。

## [13](13.cpp)

## 14

作为一个对象，使用引用以减少复制带来的性能问题。  
作为一个输出任务，只是输出，不会修改其值，因此定义为常量的引用。
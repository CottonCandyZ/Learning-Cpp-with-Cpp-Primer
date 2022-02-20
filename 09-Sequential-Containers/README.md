# 第 9 章 顺序容器

## 1

a. `list`，需要在中间插入元素。  
b. `deque`，可以双端操作，且可以随机访问。  
c. `vector`，可以很方便地读入，排序则使用标准库 `sort` 函数。


## 2

```c++
std::list<std::deque<int>> l_d_i;
```

## 3

- 指向同一个容器的元素，或是容器自后一个元素之后的位置。
- end 不在 begin 之前。

## [4](4.cpp)

## [5](5.cpp)

## 6

```c++
while(iter1 != iter2)
```

## 7

```c++
std::vector<int>::size_type
```

## 8

```c++
std::list<string>::const_iterator
std::list<string>::iterator
```

## 9

`begin` 返回普通迭代器，`cbegin` 返回 `const` 迭代器。

## 10

第一个是：`std::vector<int>::iterator`；后面的是：`std::vector<int>::const_iterator`。  
题设的代码错了，修改为：
```c++
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

## 11

```c++
vector<int> vec0; // 0
vector<int> vec1(10); // 包含 10 个，初始化 0
vector<int> vec2 = {1, 2, 3, 4, 5}; // 包含五个元素
vector<int> vec3(10, 1); // 包含 10 个，初始化 1
vector<int> vec4(vec1); // 包含 10 个，初始化 0
vector<int> vec5(++vec2.begin(), vec.end()) // 包含 4 个，分别是 2, 3, 4, 5
```

## 12

接受迭代器的版本可以接受元素类型不同的拷贝，相对地接受一个容器创建拷贝的版本不支持。

## [13](13.cpp)

## [14](14.cpp)

## [15](15.cpp)

## [16](16.cpp)

## 17

1. 同类型容器，同类型元素。
2. 容器内的元，素需要比较运算符的支持。
3. 无序容器之外的容器。

## [18](18.cpp)

## [19](19.cpp)

## [20](20.cpp)

## 21

一样的，但更耗时。

## 22

`iter` 始终不变，循环不会终止。`insert` 会改变原有迭代器的值。

修改如下：
```c++
while(iter != mid) {
    if (*iter == some_val) {
        iter = iv.insert(iter, 2 * some_value);
        ++iter;
        mid = iv.begin + iv.size() / 2 ;
    }
    ++iter;
}
```

## 23

都是一样的。

## [24](24.cpp)

## 25

什么都不会删除；删除从 elem1 到结尾的所有元素；同样，什么都不会删除。

## [26](26.cpp)

## [27](27.cpp)

## [28](28.cpp)

## 29

首先 vec 的容量会增加到 100，后 75 个元素会全部初始化为默认值。  
只保留前是个元素，其余均被删除。

## 30

得有一个无参的构造函数，或是之前提供一个构造函数。

## 31 | [list](31_list.cpp) | [forward_list](31_forward_list.cpp)

`list` 在前往下下个元素时得使用标准库函数。   
`forward_list` 属于单向链表，在处理删除或插入时要使用其前驱。

## 32

这个行为是未定义的，最终获得究竟是未 +1 的 `iter` 还是 +1 的 `iter` 是由编译器决定的。

## 33

由于插入后会影响原有的迭代器，所以插入后，`begin` 的指向将是为定义的，按照本书之前的说法，这是十分危险的行为，可能会访问到未开放的内存空间。

## [34](34.cpp)

奇数时，在其前插入一个奇数，无限循环。

## 35

`capacity`：已分配的空间（含有未使用的部分）。  
`size`：所含元素个数。

## 36

不可能。`capacity` 永远大于等于 `size`。

## 37

`list` 是链表，属于非连续分配，区别于 `vector` 的连续分配。  
`array` 是固定大小的。

## [38](38.cpp)

以 2^n 数量级增长。

## 39

```c++
vector<string> svec;
svec.reserve(1024); // 将容量至少扩充至 1024
string word;
while (cin >> word)
    svec.push_back(word); // 连续从标准输入中读取字符串，即使超过了 1024 个 string，也会自动扩充所占内存空间
svec.resize(svec.size()+svec.size()/2); // 将元素个数扩充至原始的 3/2，新的元素将以默认值 "" 填充
```

## 40

1024; 1024; 1024; 2048(clang)

## [41](41.cpp)

## 42

使用 `reserve(100)` 事先完成空间分配。

## [43](43.cpp)

## [44](44.cpp)

## [45](45.cpp)

## [46](46.cpp)

## 47 | [find_first_of](47_find_first_of.cpp) | [find_first_not_of](47_find_first_not_of.cpp)

## 48

`std::string::npos`

## [49](49.cpp)

取自常见 3000 词，符合要求的为：consciousness

## [50](50.cpp)

## [51](51.h) | [test](51.cpp)

## [52](52.cpp)
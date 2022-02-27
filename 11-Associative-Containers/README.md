# 第 11 章 关联容器

## 1

`map` 是个键值对存储。  
`vector` 是顺序存储结构，可使用位置访问。

## 2

`list` 链表应用，需要在中间增删的场景。  
`vector` 顺序表应用，需要随机访问的场景。  
`deque` 典型的队列应用。  
`map` 键值对，最典型的比如字典。  
`set` 仅需知道有没有，而不关心位置。

## [3](3.cpp)

## [4](4.cpp)

## 5

有 `key` 的用 `map`，没有的用 `set`。

## 6

`set` 是无序，且不可重复的。`list` 是有序的，且可重复的。

## [7](7.cpp)

## [8](8.cpp)

优点：自动去除重复元素。

## 9

```c++
std::map<std::string, std::list<int>> words;
```

## [10](10.cpp)

`list` 的 `iterator` 没有定义 `<` 运算，所以无法编译。`vector` 是可以的。

## [11](11.cpp)

## [12](12.cpp)

## [13](13.cpp)

## [14](14.cpp)

## 15

`mapped_type` : `vector<int>`  
`key_type` : `int`  
`value_type` : `pair<int, vector<int>>`

## [16](16.cpp)

## 17

```c++
copy(v.begin(), v.end(), inserter(c, c.end())); // 合法
copy(v.begin(), v.end(), back_inserter(c)); // 不合法
copy(c.begin(), c.end(), inserter(v, v.end())); // 合法
copy(c.begin(), c.end(), back_inserter(v)); // 合法
```

## 18

```c++
std::map<const std::string, size_t>::iterator; // 错误
std::map<std::string, size_t>::const_iterator; // 正确
```

## 19

std::multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)>::iterator;

## [20](20.cpp)

## 21

将插入的新单词计数器置为 1，或将原有的单词计数器 +1。

## 22

```c++
// 省略命名空间前缀
pair<string, vector<int>>;
pair<map<string, vector<int>>::iterator, bool>;
```
√
## [23](23.cpp)

## 24

**添加**一个 `key` 为 0，值为 1 的值到 `map` 中。

## 25

将位置为 0 的元素**置**为 1。// 区别已加粗

## [26](26.cpp)

## 27

仅仅需要计数时完全可以考虑用 `count`，需要找到其位置 或 仅仅判断其是否存在时，可以考虑使用 `find`。

## 28

```c++
std::map<std::string, std::vector<int>> m{{"hello", {1, 2}}};
std::map<std::string, std::vector<int>>::iterator iter = m.find("hello");
```

## 29

`upper_bound` 和 `lower_bound` 都会返回关键字可以插入的位置。    
`equal_range` 返回一个 `pair` 包含两个迭代器，这两个迭代器都指向相同的位置，为所查关键字可以插入的位置。

## 30

`pos` 是由 `equal_range` 返回的，是一个 `pair`，第一个指向关键字开始的迭代器，第二个指向关键字结束的后一个迭代器。    
`pos.first` 返回第一个迭代器，即得到元素开始到结束前的位置的迭代器。    
`pos.first->second` 迭代器是一个 `pair` 的指针，故这实际上在访问这个 `pair` 的第二个元素，是一个指向 `mapped_value` 的值，即 `map` 所含键值对中的 值。

## [31](31.cpp)

## [32](32.cpp)

## [33](33.cpp)

## 34

由于传入的是 `map` 是个常量引用，本身就不可修改。对于可修改的情况下，如果访问的是个不存在的值，则会新建一个 key，然后返回一个空值。
所以对于查找任务，应该用 `find`，对于添加和修改任务，应该使用下标访问。

## 35

如果 `key` 已经存在，则 `insert` 什么也不做。相比之下下标访问则会修改已存在的值。对于题设的情况，假设不会出现重复的 `key`，则两个结果是一样的。

## 36

等价于将对应的关键字删除，不会对其余的关键字产生影响，程序也将正常运行。

## 37

主要是性能问题，无序容器的性能更优。维护有序是需要牺牲一些性能的。  
可以使用迭代器顺序访问。

## 38 | [word_count](38_word_count.cpp) | [word_transform](38_word_transform.cpp)
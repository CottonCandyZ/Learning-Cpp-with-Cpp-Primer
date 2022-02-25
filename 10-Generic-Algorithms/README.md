# 第 10 章 泛型算法

## [1](1.cpp)

## [2](2.cpp)

## [3](3.cpp)

## 4

会被转化成 `int` 相加。`start += first`，会导致结果变为 `int`。

## 5

使用符号比较两个 C 风格字符串，实际上是在比较两个指针的地址，应该使用库函数 `strcmp` 完成比较。

## [6](6.cpp)

## [7](7.cpp)

```c++
a.  std::vector<int> vec;
    std::list<int> lst;
    int i;
    while (std::cin >> i) {
        lst.push_back(i);
    } // 或者使用 resize 将 vector 调整至 lst 的大小
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec)); // 改为使用 back_inserter，因其没有初始化
b.  std::vector<int> vec;
    vec.reserve(10); // 分配空间没用，得占位，这一行可以选择去掉或改为 resize(10)
    std::fill_n(std::back_inserter(vec), 10, 0); // 或使用 back_inserter
```

## 8

这是借用迭代器的接口完成的，插入的工作由迭代器完成，而标准库算法仅仅以同样的方式使用迭代器。

## [9](9.cpp)

## 10

算法应该和添加及删除的操作分开，这是一种设计原则。

## [11](11.cpp)

## [12](12.cpp)

## [13](13.cpp)

## 14

```c++
[](int first, int second) { return first + second; }
```

## 15

```c++
[int_num](int par) { return int_num + par; }
```

## [16](16.cpp)

## [17](17.cpp)

## [18](18.cpp)

## [19](19.cpp)

## [20](20.cpp)

## [21](21.cpp)

## [22](22.cpp)

## 23

所绑定的函数有 n 个参数，则 `bind()` 将会有 n+1 个参数。

## [24](24.cpp)

## [25](25.cpp)

## 26

`back_inserter` 等价于 `push_back`，始终于末尾插入。  
`front_inserer` 等价于 `push_front` 始终于头部插入。  
`inserter` 于指定迭代器前插入。若是在 `begin()` 位置插入，则实际始终指向 `end()`。

## [27](27.cpp)

发现其只会删除相连重复的，对于间断重复无法消除。

## [28](28.cpp)

## [29](29.cpp)

## [30](30.cpp)

## [31](31.cpp)

## [32](32.cpp)

## [33](33.cpp)

## [34](34.cpp)

## [35](35.cpp)

## [36](36.cpp)

## [37](37.cpp)

## 38

- 输入迭代器：`==`, `!=`, `++`, `*`, `->`, 仅读。
- 输出迭代器：`++`, `*`, 仅写。
- 前向迭代器：`==`, `!=`, `++`, `*`, `->`, 读写。
- 双向迭代器：`==`, `!=`, `++`, `--`, `*`, `->`, 读写。
- 随机访问迭代器：`==`, `!=`, `++`, `--`, `*`, `->`, `<`, `<=`, `>`, `>=`, `+`, `+=`, `-`, `-=`, 
下标运算，两个迭代器相减，读写。

## 39

`list` 双向迭代器。  
`vector` 随机阿福给你问迭代器。

## 40

`copy` 支持输出的迭代器 + 支持输入的迭代器。  
`reverse` 双向迭代器。（两个往中间移动）  
`unique` 前向迭代器。（只是删除连续相同的元素）

## 41

```c++
replace(beg, end, old_val, new_val); // 将从迭代器 beg 到 end 之前的元素中含有 old_val 的全部替换为 new_val
replace_if(beg, end, pred, new_val); // pred 应该接受一个函数，根据其测试条件将 beg 和 end 之前的元素为 true 的替换为 new_val
replace_copy(beg, end, dest, old_val, new_val); // 将 begin 到 end 之前的元素拷贝到 dest 的同时将 old_val 替换为 new_val
replace_copy_if(beg, end, dest, pred, new_val); // 将 begin 到 end 之前的元素拷贝到 dest 的同时将 pred 为 true 的替换为 new_val
```

## [42](42.cpp)
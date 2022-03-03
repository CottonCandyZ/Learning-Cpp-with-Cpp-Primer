# 第 12 章 动态内存

## 1

`b2` 四个，`b1` 三个。

## [2](StrBlob_1.h)

## 3

这里涉及到一个设计问题，类的设计者没有设计 `const` 版本的 `front` 或 `back` 时，
若类的使用者使用 `StrBlob` 声明一个常量对象，那么理论上是不可以修改它的，
这时候若尝试去访问 `front` 和 `back` 时是会被拒绝，因为他们会更改对象的值。

相反，若设计了含 `const` 的版本，则相同的使用方式下，可以使用 `front` 和 `back`，但此时由于返回的是引用，因此也可以修改内部的值。

所以，若希望使用者在使用 `const` 声明时，不能调用 `front` 和 `back`，那么可以不引入 `const` 的版本。  
若希望使用者在使用 `const` 声明时，可以调用这两个函数，则应该引入 `const` 版本。

## 4

<del>`check` 是一个 `private` 函数，也就是类设计这而非使用者可以访问的函数，因此在使用时，可以由设计者保证其输入的合法性。</del>

`size_type` 是一个无符号数。


## 5

优点：  
便于直接初始化，而无序使用构造函数。

缺点：  
有一定的迷惑性，转化不够明确。

实际上以上的优缺点都来自隐式转换的优缺点。[7.47](../07-Classes/README.md#47)

## [6](6.cpp)

## [7](7.cpp)

## 8

分配了内存后忘了释放。

## 9

```c++
int *q = new int(42), *r = new int(100);
r = q; // r 是 q 指针的副本。两个值相同。r 原先指向的区域没有被正确释放，会导致内存泄漏。
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2; // r2 作为 q2 的副本。r2 引用计数减为 0，会自动释放内存。
```

## [10](10.cpp)

正确的。

```c++
shared_ptr<int> p(new int(42)); // 创建一个 shared_ptr
// 由 p 初始化一个新的 shared_ptr 并传入 process，此时 p 的计数器 +1 变成 2，在 process 执行完后，计数变为 1。
process(shared_ptr<int>(p));
```
## [11](11.cpp)

报错：

```
12-11(54218,0x10f30d600) malloc: *** error for object 0x600001e6c030: pointer being freed was not allocated
12-11(54218,0x10f30d600) malloc: *** set a breakpoint in malloc_error_break to debug
```

理由：传入的 p 被释放了，后来 `shared_ptr` 的 `destroy` 函数执行时发生了以上的错误。

## 12

```c++
auto p = new int();
auto sp = make_shared<int>();
a. process(sp); // 合法，引用计数 +1，结束后 -1
b. process(new int()); // 不合法，必须显式类型转换
c. process(p); // 不合法，理由同上
d. process(shared_ptr<int>(p)); // 合法，但执行完成后 p 所指向区域的内存已被释放，随后若是尝试访问 p 的行为是未定义的
```

## [13](13.cpp)

这题和上面的 [11](#1111cpp) 是一样的效果，会直接报错（错误同上），原因是尝试释放了本应该由 `shared_ptr` 自主释放的内存空间，
这会导致再程序结束时，该空间被释放两次，因此会报 `pointer being freed was not allocated` 的错误。


## [14](14.cpp)

## [15](15.cpp)

## [16](16.cpp)

## [17](17.cpp)

```c++

a. IntP p0(ix); // 不可以，显然不支持直接用 int 初始化
b. IntP p1(pi); // 可以编译，但执行报错可以，由于 ix 不是动态内存分配出来的，所以会被自动回收，而 unique_ptr 的析构函数会再次回收，会导致 pointer being freed was not allocated 错误
c. IntP p2(pi2); // 可 但是会导致 pi2 指向未知区域
d. IntP p3(&ix); // 不可 同 b
e. IntP p4(new int(2048)); // 可
f. IntP p5(p2.get()); // 不可，会导致回收两次，导致一个错误：pointer being freed was not allocated
```

## 18

没有意义，`shared_ptr` 会自动回收。

## 19 [StarBlobPtr](StrBlobPtr_1.h) | [StarBlob](StrBlob_2.h)

## [20](20.cpp)

## 21

之前的版本，显然更加清晰，便于阅读。

## [22](ConstStrBlobPtr.h)

## [23](23.cpp)

## [24](24.cpp)

## 25

```c++
delete [] pa;
```

## [26](26.cpp)

## 27 | [TextQuery](TextQuery_1.h) | [QueryResult](QueryResult_1.h)

## [28](28.cpp)

## 29

`do...while` 无论如何都会执行一次。在这个程序中观感更好。

```c++
do {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
} while(true);
```

## [30](30.cpp) | [TextQuery](TextQuery_2.h) | [QueryResult](QueryResult_2.h)

## 31

需要检查重复元素，`set` 更好，会自行处理。

## [32](32.cpp) | [TextQuery](TextQuery_3.h) | [QueryResult](QueryResult_3.h)

## 33 | [QueryResult](QueryResult_4.h)
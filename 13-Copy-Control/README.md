# 第 13 章 拷贝控制

## 1

是什么：是一个参数为自身引用的构造函数。  
什么时候：定义了当用同类型的另一个对象**初始化**本对象时做什么。

## 2

没有采取引用，会导致拷贝无限循环。最好使用 `const` 修饰（非必须）。

## 3

会调用 `share_ptr` 的拷贝函数来拷贝 `data`，引用计数 +1。  
会调用 `vector` 的拷贝函数来拷贝 `vec_string`，`curr` 作为内置类型，直接复制，而 `weak_ptr` 类型的 `wptr` 会发生拷贝，但引用计数不会改变。

## 4

```c++
Point global;
Point foo_bar(Point arg) {  // 实参拷贝构造 1
    Point local = arg, // 拷贝初始化时调用 2
                  *heap = new Point(global); // 拷贝构造 3
    *heap = local; // 仅拷贝，没调用拷贝构造
    Point pa[ 4 ] = {loacl, *heap}; // 拷贝构造，初始化列表 4 5
    return *heap; // 拷贝构造，返回类型非引用 6
}
```

## [5](HasPtr_1.h)

## 6

是什么：是一个重载 `=` 运算符的函数。  
什么时候用：定义了将一个对象赋予同类型的另一个对象时做什么。  
完成什么工作：拷贝除 `static` 修饰的对象内的成员。  
什么时候生成合成拷贝赋值运算符：不主动声明时。

## 7

和 [3](#3) 是一样的。

## [8](HasPtr_2.h)

## 9

是什么：一个由 `~` + 类名构成的函数，没有返回值，也不接受参数。  
完成什么工作：在对象最后一次使用后，析构函数的函数体可执行类设计者希望执行的任何收尾工作。通常，析构函数释放对象在生存期分配的所有资源。  
什么时候生成合成的：未主动定义时。

## 10

`StrBlob` 里有个有个 `shared_ptr` 成员，在销毁时，会检查其引用计数，若引用计数减为 0，则回收该内存空间。  
`StrBlobPtr` 里的内置对象直接释放空间，对于 `weak_ptr`，则什么也不做。

## [11](HasPtr_3.h)

## 12

```c++
bool fcn(const Sales_data *trans, Sales_data accum) { // 拷贝创建 accum
    Sales_data item1(*trans), item2(accum); // 拷贝创建 item1, item2
    return item1.isbn() != item2.isbn();
}
```
共三个对象，析构三次。

## [13](13.cpp)

## 14

输出三个相同的序号。

## 15

会改变，注意到 `f` 传递的并非引用，所以每次调用都会使用拷贝构造函数创建一个新的 `numbered` 对象，
所以会是三个不同值（若拷贝构造函数保证每次生成数唯一的话）。

## 16

会改变，`b = a`, `c = b` 也会调用拷贝构造函数，因此三个序号是不同的。

## [17](17.cpp)

## 18 | [Employee_1](Employee_1.h)

## 19 | [Employee_2](Employee_2.h)

不需要，`Employee` 不需要拷贝。

## 20

两个成员：`shared_ptr` 和 `map` 将会被拷贝。  
销毁时需要判断 `shared_ptr` 引用计数。

## 21

不需要，因为其使用的 `shared_ptr` 和 `map` 在生成的拷贝函数下都可以正常工作。

## [22](HasPtr_4.h)

和 [11](#11hasptr_3h) 一致，没有变化。

## 23

在 [8](#8hasptr_2h) 中已经思考过该问题。

## 24

未定义析构函数：在离开其作用域范围时，不会销毁 `ps` 指针指向的内存空间。  
未定义拷贝构造函数：会导致它的行为像一个指针，两个对象的 `ps` 将指向同一个空间。

## 25

做什么：由于是类值，因此只复制值本身。  
为什么不需要析构函数：由于使用 `shared_ptr`，因此生成的析构函数足以完成析构任务。

## [26](StrBlob_3.h)

## [27](HasPtr_5.h)

## 28

[a](28_a.h) | [b](28_b.h)

## 29

不会，他们调用的是标准库重载函数，自然不会发生递归。

## [30](HasPtr_6.h)

## [31](31.cpp) | [HasPtr](HasPtr_7.h)

## 32

不会受益，类值版本的会受益因为其若使用原版 `swap`，那么会导致内存非配与回收，而类指针的版本不存在此问题。

## 33 

为何不能是 `Folder`：如果不使用引用，则无法完成 `f.addMsg(this);` 的操作。  
为何不声明为常量？：因为要修改 `Folder`。

## 34 [Message](Message_1.h)

## 35

不会更新对应 `folder` 中指向其的值，无法做到反向修改。

## 36 [Folder](Folder_1.h)

## 37 [Message](Message_2.h)

## 38

考虑一下自赋值的情况，是没有问题的。实际上是由于未使用动态内存分配和指针。

## 39 [StrVec](StrVec_1.h)

## 40 [StrVec](StrVec_2.h)

## 41

会导致前面空一个，并且 `first_free` 将指向刚加进去的元素。

## [42](42.cpp) [TextQuery](TextQuery_4.h) | [QueryResult](QueryResult_5.h)

## 43 [StrVec](StrVec_3.h)

新的更加好，相比原始 `for` 更加简洁，不用自己写遍历过程。

## [44](44.cpp) | [String](String_1.h)

## 45

右值引用：接受右值，字面常量 or 表达式求值结果。  
左值引用：接受左值，左值有持久状态。（别名）

## 46

```c++
int f();
vector<int> vi(100);
int &&r1 = f();
int & r2 = vi[0];
int & r3 = r1;
int &&r4 = vi[0] * f();
```

## 47 [String](String_2.h)

## [48](48.cpp)

## 49 [StrVec](StrVec_4.h) | [String](String_3.h) | [Message](Message_3.h)

## [50](50.cpp) | [String](String_4.h)

## 51

因为 `unique_ptr` 实现了移动控制函数，返回时是一个右值，移动控制函数完成的是接管而非拷贝。

## 52

`hp = hp2` 时，调用赋值运算符，会将 `hp2` 拷贝给 `rhs`，随后交换的 `rhs` 和 `hp` 的值，则 `hp` 将成为 `hp2` 的副本，其本身的值被销毁。  
`hp = std::move(hp2)` 是，调用赋值运算符，由于调用 `move` 函数，将其转化为右值，因此赋值给 `rhs` 时调用的是移动构造函数，因此 `rhs`
接管了 `hp2`，`hp` 将会和 `rhs` 交换，并接管 `hp2` 的值，而 `hp` 的值将被销毁。

## 53 [HasPtr](HasPtr_8.h)

reference: [SO](https://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a)

## [54](54.cpp) [HasPtr](HasPtr_9.h)

报编译错：
```
Use of overloaded operator '=' is ambiguous (with operand types 'HasPtr' and 'typename remove_reference<HasPtr &>::type' (aka 'HasPtr'))
```

显然由于两个函数在接收的类型上一致了，导致匹配时没有最优解，从而导致冲突。

## [55](StrBlob_4.h)

## 56

递归到爆栈，因为返回时用左值调用，而其调用便是自身。

## 57

会调用对应右值的 `sorted()` 函数。

## [58](58.cpp) [Foo](Foo_1.h)
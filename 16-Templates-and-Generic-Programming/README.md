# 第 16 章 模版与泛型编程

# 1

> 当调用一个模版时，编译器（通常）用函数实参来为我们推断模版十参。编译器推断出的模版参数来为我们实例化一个特定版本的函数。

故实例化实则是从模版创建符合特定需求的函数。

## [2](2.cpp)

## [3](3.cpp)

```
error: invalid operands to binary expression ('const Sales_data' and 'const Sales_data')
if (v2 < v1) return 1;
    ~~ ^ ~~
```

## [4](4.cpp)

## [5](5.cpp)

## [6](6.cpp)

## [7](7.cpp)

## 8

大部分类型没有定义 `<` 运算符，但大部分类型定义了 `==` 和 `!=` 运算符。

## 9

函数模版：通用函数生成公式，可用来生成针对特定类型的函数版本。  
类模版：用来生成类的蓝图的。  
不同点：编译器不能为类模版推断模版参数类型。

## 10

以特定的类型填充对应的类型。

## [11](11.cpp)

## 12 [Blob](Blob_1.h) | [BlobPtr](BlobPtr_1.h)

## 13

一对一友好关系，即每个 `Blob` 实例将相同实例化的 `BlobPtr` 作为友元。

## [14](14.cpp) | [Screen](Screen_4.h)

## [15](15.cpp) | [Screen](Screen_5.h)

可采用一对一友好关系。

## 16 [Vec](Vec_1.h)

## 17

没有。当需要显式告诉编译器该名字是一个类型时，必须使用 `typename`。

## 18

```c++
a. template <typename T, U, typename V> void f1(T, U, V); // U 缺少一个 typename 修饰
b. template <typename T> T f2(int &T); // 将模版参数用作变量名导致冲突
c. inline template <typename T> T foo(T, unsigned int*); // inline 放在 template 后面
d. template <typename T> f4(T, T); // 缺少返回值
e. typedef char Ctype;
   template <typename Ctype> Ctype f5(Ctype a); // typename 会将 typedef 声明的 Ctype 隐藏
```

修改后：
```c++
a. template <typename T, typename U, typename V> void f1(T, U, V);
b. template <typename T> T f2(int &);
c. template <typename T> inline T foo(T, unsigned int*);
d. template <typename T> void f4(T, T);
e. typedef char Ctype;
   template <typename T> T f5(Ctype a);
```

## [19](19.cpp)

## [20](20.cpp)

## 21 [DebugDelete](DebugDelete_1.h)

## 22 [TextQuery](TextQuery_5.h) | [QueryResult](QueryResult_5.h)

## [23](23.cpp)

可以查看输入 `q` 之后的输出

## 24 [Blob](Blob_2.h)

## 25

```c++
extern template calss vector<string>; // 声明已经实例化的模版
template class vector<Sales_data>; // 实例化定义，以完全实例化给后期直接使用
```

## 26

不可以，`vector` 会完成一个初始化，此时需要 `NoDefault` 的构造函数。

## 27

a 没有实例化，作为形参；  
b 没有实例化，因为仅仅声明引用；  
c 实例化了；  
d 作为一个指针，没有实例化；  
e 实例化了；  
参考：[SO](https://stackoverflow.com/questions/21598635/how-is-a-template-instantiated)

## [28](28.cpp) | [shared_ptr](SharedPtr_1.h) | [unique_ptr](UniquePtr_1.h)

## 29 [Blob](Blob_3.h)

## [30](30.cpp)

## 31

参见 [28](28.cpp)，将会在编译时编译成内联形式。

## 32

编译器使用函数调用中的实参类型来寻找模版实参，用这些模版实参生成的函数版本与给定的函数调用最为匹配。

## 33

- `const` 转换：将一个非 `const` 对象的引用（或指针）传递给一个 `const` 的引用（或指针）形参。
- 数组或函数指针的转换：前提函数形参不是引用类型。数组 -> 一个指向首元素的指针；函数实参 -> 该函数类型的指针

## 34

a. 不合法，两个不等长。分别为 `char(&)[2]` 和 `char(&)[5]`。  
b. 合法，两个等长。类型为：`chat(&)[3]`。

## 35

a. 没错，类型为 `char`。但是第二个实参会被类型转换为 `int`。  
b. 没错，类型为 `double`。第二个实参同样会被转换为 `int`。  
c. 没错，类型为 `char`。  
d. 错误，两个类型不同。

## 36

有一些语法错误：两个函数都没有返回值；`f2` 的 `template` 使用的是尖括号。  


a. 合法。`T` 的类型为 `int *`。  
b. 合法。两个类型都为 `int *`。  
c. 合法，类型为 `const int *`。  
d. 合法，两个类型都为 `const int *`。  
e. 不合法，第二个参数为一个底层 `const`。  
f. 合法，类型分别为 `int *` 和 `const int *`。

## [37](37.cpp)

```c++
int i = 1;
double d = 15;
std::max<double>(i, d);
```

## 38

使用 `make_shared` 时，可以不给参数，因此无法完成类型推断，我们需要显式给出。

## [39](39.cpp)

## 40

合法，但是只能使用可以使用 `+ 0` 操作的元素类型，返回的是 `+` 返回的值。

## 41 [sum](sum_1.h)

## 42

```c++
a. g(i); // T: int&, val: int&
b. g(ci); // T: const int&, val: const int&
c. g(i * ci); // T: int, val: int&&
```

## 43

`i = ci` 返回的是 `i`，因此和 `g(i)` 的结果一样，为 `T: int&, val: int&`

## 44

当是 `T` 时：
```c++
a. g(i); // T: int, val: int
b. g(ci); // T: int, val: int
c. g(i * ci); // T: int, val: int
```

当是 `const T&` 时：
```c++
a. g(i); // T: int, val: const int&
b. g(ci); // T: int, val: const int&
c. g(i * ci); // T: int, val: const int&
```

## 45

会创建 `vector<int>` 类型的变量 `v`，会创建 `vector<int&>` 类型的变量 `v`。

## 46

使用 `std::move(*elem++)` 将 `elem` 转换为右值引用，此时就会调用 `std::allocator::construct` 的移动构造版本，完成移动。

## [47](47.cpp)

## [48](debug_rep_1.h)

## 49

```c++
g(42); // 调用 g(T) 的版本，T 实例化为 int
g(p); // 调用 g(T*) 的版本，T 实例化为 int
g(ci); // 调用 g(T) 的版本，T 实例化为 const int
g(p2); // 调用 g(T*) 的版本，T 实例化为 const int

f(42); // 调用 f(T) 的版本，T 实例化为 int
f(p); // 调用 f(T) 的版本，T 实例化为 int*
f(ci); // 调用 f(T) 的版本，T 实例化为 const int
f(p2); // 调用 f(const T*) 的版本，T 实例化为 int
```

## [50](50.cpp)

## 51

```c++
foo(i, s, 42, d); // 3 3
foo(s, 41, "hi"); // 2 2
foo(d, s); // 1 1
foo("hi"); // 0 0
return 0;
```

## [52](52.cpp)

## [53](53.cpp) 

## [54](54.cpp)

会报编译错：`error: invalid operands to binary expression`。

## [55](55.cpp)

因为缺少参数而产生错误：`no matching function for call to 'print'`。

## [56](56.cpp)

## 57

使用 `errorMsg` 的  
优点：可以同时打印不同类型的元素，使代码更加简洁。  
缺点：难以检查错误。

使用 `error_msg` 的  
优点：简单，易于编写，易于排错。  
缺点：无法传入不同类型的值。会发生类型转换。对于不同类型需要多次调用。

## 58 [StrVec](StrVec_9.h) | [Vec](Vec_2.h)

## [59](59.cpp)

使用左值的拷贝构造，而非直接构造，其过程和 `push_back` 是一致的，分配空间，并存入。

## 60

如果传递的是一个右值，则应该会使用直接构造，接管这个右值。如果传递左值，则会调用左值拷贝构造，复制一次。

## [61](61.cpp)

## [62](62.cpp)

## [63](63.cpp)

## [64](64.cpp)

## [65](debug_rep_2.h)

## 66

> overload when you can, specialise when you need to.

所以能用重载就用重载，当特别需要特例化时，就选择特例化。

优点：编译器会优先选择。重载时可以避免原始类型的限制。
缺点：无法在命名空间内重载，有些不得不使用特例化，例如 `hash`。

[SO](https://stackoverflow.com/questions/7108033/template-specialization-vs-function-overloading)

## 67

不会。他们仅仅是实例化一个特例，不会影响其原有的匹配。

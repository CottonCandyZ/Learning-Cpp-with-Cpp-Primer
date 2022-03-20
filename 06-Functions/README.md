# 第 6 章 函数

## 1

实参是传入参数用来初始化形参。形参用于表示传入的参数，定义于函数体上。

## 2

错误：
```c++
(a) int f() {  // 返回值是 string 不是 int
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }  // 缺少返回类型
(c) int calc(int v1, int v1) { /* ... */ }  // 尝试使用相同的形参名
(d) double square (double x) { return x * x; }  // 花括号是必须的
```

修正：
```c++
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

## [3](3.cpp)

## [4](4.cpp)

## [5](5.cpp)

## 6

形参：属于函数的参数列表  
局部变量：在花括号（块内）的  
局部静态变量：第一次声明时被创建，程序结束时才被回收

```c++
size_t count_call(size_t times) { // times 时参数
    static size_t ctr = 0; // 局部静态变量
    return ++ctr * times;
}

int main() {
    for (size_t i = 0; i != 10; ++i) { // i 局部变量
        cout << count_call(i) << endl;
    }
    return 0;
}
```

## [7](7.cpp)

## [8](Chapter6.h)

## [9](9)

使用 cmake 编译。

## [10](10.cpp)

## [11](11.cpp)

## [12](12.cpp)

引用更易于使用，引用比指针更加简洁。

## 13

`void f(T)` 保证不会改变传入的值的原始对象。`void f(T&)` 可能会改变传入的值的原始对象。

## 14

```c++
void reset(int &i) {
    i = 0;
}

void print(int start, int end /*, ... */ ) { // start 和 end 可能是临时变量
    for (; start != end; ++start) { // 会改变 start 的值
         /* std::cout << ... */
    }
}
```

## 15

`s` 不会改变，且可以传递字面值，`occurs` 是显然需要修改的，自然是普通引用。  
`c` 同样可以是字面值：`find_char(s, 'o', ctr)`。  
显然能声明成常量引用的就应该声明为常量引用，因为其将带来很多的好处。

`++occurs` 不会执行。

## 16

函数内部没有尝试改变 s 的值，使用普通引用会有局限性，改为常量引用会提高适用性。

```c++
bool is_empty(const string &s) { // 将普通常量改为常量的引用
    return s.empty();
}
```

## [17](17.cpp)

## 18

```c++
bool compare(const matrix &m1, const matrix &m2); // 比较两个矩阵
vector<int>::iterator change_val(int i , vector<int>::iterator i_iter); // 改变迭代器所指向的函数值
```

## 19

a. 不合法，多了个参数  
b. 合法  
c. 合法  
d. 合法

## 20

能用的时候尽量使用。可能会改变传入的原始值，且无法使用字面量或是顶层 `const` 值传入。

## [21](21.cpp)

`const int * const par_name`

## [22](22.cpp)

## [23](23.cpp)

## 24

`void print(const int ia[10])` 等价于 `void print(const int *ia)`。  
所以传入的值无法保证不越界。

更改为：`void print(const int (&ia)[10])`。


## [25](25.cpp)

## [26](26.cpp)

## [27](27.cpp)

## 28

`const std::string &`

## 29

应该，可以减少复制。但是对于内置类型实际上可以忽略，因为内部类型的拷贝非常 cheap。

## [30](30.cpp)

## 31

函数内部创建的变量（局部变量），局部临时变量。不是左值的时候。

## 32

合法，为数组的每个值赋上其下标。

## [33](33.cpp)

## 34

如果是正数：结果都是 0，最后都会乘上 0。

如果是负数：则将是无尽的递归。

## 35

传入 `val--` 毫无意义，实际上是以不变的值传入的，递归将不会结束。

## 36

```c++
std::string (&func(std::string (&str_arr)[10]))[10];
```

## 37

```c++
using string_arr = std::string[10];
string_arr &func(string_arr &str_arr)

auto func(std::string (&str_arrp)[10]) -> std::string(&)[10]

std::string string_arr[10];
decltype(string_arr) &func(decltype(string_arr) &str_arr);
```

## 38

```c++
decltype(odd) &arrPtr(int i) {
    return (i % 2) > odd : even;
}
```

## 39

a. 调用形式上无区别，非法的。  
b. 仅返回值不同，非法的。  
c. 合理。

## 40

a. 正确，有默认实参时，其后的实参也得是默认实参。  
b. 错误，解释同上。

## 41

a. 非法，第一个实参必须给值。  
b. 正确，改变了第二个默认值。  
c. 合法，但是不符程序员的初衷，尝试将一个 `char` 值赋给 `int` 型参数。

## [42](42.cpp)

## 43

a. 放在头文件中，因为其是内联函数的多个定义需完全一致。  
b. 放在源文件中，其为普通函数

## 44

```c++
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
```

## 45

[42](#42) 显然可以换成内联函数，但是 [4](#4) 显然不可以。

## 46

不能，传入的 string 的长度是不确定的。std::string 不是字面量类型。

## [47](47.cpp)

## 48

不合理，`assert` 通常用来检查某些不发生的情况，而检查 cin 是可能发生的情况。

## 49

候选函数：具有相同函数名的函数；  
可行函数，能够通过类型转换或直接赋值调用的函数。

## 50

a. 具有二义性 `f(int, int)` 和 `f(double, double = 3.14)`。  
b. `f(int)`.  
c. `f(int, int)`.  
d. `f(double, double = 3.24)`.

## [51](51.cpp)

## 52

a. 类型提升。第三级。  
b. 算数类型转换。第四级。

## 53

a&b. 均为底层 const，此函数可以接受常量的引用及指针。  
c. 非法，这是一个顶层 const，将会带来二义性。

## 54

```c++
int func(int, int);
std::vector<decltype(func) *> vec;
```

## [55](55.cpp)

## [56](56.cpp)

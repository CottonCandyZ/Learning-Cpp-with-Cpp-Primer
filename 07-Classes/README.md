# 第 7 章 类

## [1](1.cpp)

## [2](Sales_data_1.h)

## [3](3.cpp)

## [4](Person_1.h)

## [5](Person_2.h)

当然可以使用 `const`，因为不会修改成员变量的值。

## [6](Sales_data_2.h)

## [7](7.cpp)

## 8

read 显然需要修改，而 print 不会发生修改。

## [9](Person_3.h)

## 10

是否能够正确的读入两个 data。

## [11](11.cpp)

[Sales_data_3](Sales_data_3.h)

## [12](Sales_data_4.h)

## [13](13.cpp)

## 14

```c++
Sales_data() : units_sold(0), revenue(0) {}
```
## [15](Person_4.h)

## 16

次数没有限制，所控范围为下一个访问符之前。外部可以访问的在 `public` 之后，外部不可以访问的在 `private` 之后。

## 17

唯一区别就是默认访问权限。

## 18

含义：隐藏类的实现细节

有效降低耦合。只提供接口访问，而不是直接访问数据成员。
若类内部发生改变，用户无需修改调用代码。

## 19

```c++
struct Person {
public: // 构造函数，及访问函数都采用 public
    Person() = default;

    Person(const std::string &name, const std::string &address) :
            name(name), address(address) {}

    Person(std::istream &is) {
        read(is, *this);
    }

    std::string getName() const { return name; }

    std::string getAddress() const { return address; }
private: // 数据成员应该采用 private，避免直接访问
    std::string name;
    std::string address;
};
```

## 20

用途：要访问类内部的 `private` 成员的函数或其他类。  
利：访问内部成员更加方便。  
弊：需要两次声明，外部才能访问。

## [21](Sales_data_5.h)

## [22](Person_5.h)

## [23 & 24](Screen_1.h)

## 25

可以的，因其使用内置变量和 string，这两个都可以使用默认的复制方案。

## [26](Sales_data_6.h)

## [27](27.cpp) | [Screen](Screen_2.h)

## 28

两次调用 `display` 的结果将会不同。
第一次调用结果：`XXXXXXXXXXXXXXXXXXXX#XXXX`  
第二次调用结果：`XXXXXXXXXXXXXXXXXXXXXXXXX`

## [29](29.cpp) | [Screen](Screen_2_e.h)

## 30

优点：更加明确所访问的究竟是成员还是可能同名的形参。  
缺点：多此一举。

## [31](31.h)

## 32 | [Window_mgr](Window_mgr_2.h) | [Screen](Screen_3.h)

## 33

```c++
Screeen::pos  Screen::size() const {
    return hegith * width;
}
```

## 34

上面的 pos 都将报错。

## 35

内部重复定义，去掉外侧或内侧的。

## 36

```c++
struct X {
    X (int i, int j) : base(i), rem(i % j) {}
};
```

## 37

```c++
Sales_data first_item(cin);   // use Sales_data(std::istream &is); 输入的

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## 38

```c++
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## 39

两个构造函数在形式上都是一样的，不满足重载的要求，因此会发生冲突。

## 40

比如 Date:

```c++
class Date{
    friend std::ostream &operator<<(std::ostream &, const Date &);
public:
    Date() = default;
    Date(unsigned _year, unsigned _month, unsigned _day) : year(_year), month(_month), day(_day) { }
    Date(std::istream &in) { in >> year >> month >> day; }
private:
    unsigned year;
    unsigned month;
    unsigned day;
};

```

## [41](41.cpp) | [Sales_data](Sales_data_7.h)

## 42

```c++
class Date{
    friend std::ostream &operator<<(std::ostream &, const Date &);
public:
    Date() : Date(0, 0, 0, 0) { }
    Date(unsigned _year, unsigned _month, unsigned _day) : year(_year), month(_month), day(_day) { }
    Date(std::istream &in) { in >> year >> month >> day; }
private:
    unsigned year;
    unsigned month;
    unsigned day;
};
```
## [43](43.h)

## 44

不合法，`NoDefault` 没有默认构造函数。

## 45

合法，C 存在默认构造函数。

## 46

a. 不正确，可以不提供，会有一个默认构造函数。  
b. 不是，这里说的默认是指其生成的。  
c. 不正确，会提供。  
d. 没有定义任何构造函数才会提供，并且为期生成默认值的前提是其成员对象存在默认值。

## 47

应该是 `explicit` 的，因为直接赋值会产生迷惑性。

## 48

都是一样的，都会创建两个 `Sales_data` 对象

## 49

a. 可以。  
b. 不可以，这将会引用一个零时变量。  
c. 尾部的 `const` 不应该有，因为这个 combine 会改变调用对象的值。

## 50

```c++
explicit Person(std::istream &is)
```

## 51

例子：
```c++
int getSize(const std::vector<int>&);
getSize(34); // 令人困惑

void setYourName(std::string);
setYourName("CCZ"); // 没有问题
```

## 52

将类内初始值去除：
```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## [53](Debug.h)

## 54

不可以，`constexpr` 函数只可以有 `return` 语句。

## 55

不是，`string` 不是字面值类型，无法提供一个 `constexpr` 构造函数。

## 56

由 `static` 标记的成员为静态成员，类属于这个类。  
优点：独立于对象，生命周期为整个程序。  
区别：可以是不完全类型，而普通成员不可以；可以用作默认实参。

## [57](Account.h)

## 58

静态变量的初始化问题，放在类内部的话应当为常量。

```c++

// example.h
class Example {
public:
static constexpr double rate = 6.5; // 补上 constexpr
static const int vecSize = 20;
static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize); // 初始化放在外部
```
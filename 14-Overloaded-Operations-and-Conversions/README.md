# 第 14 章

## 1

区别：
- 重载运算符可以通过函数调用。
- 重载运算符要求其中一个是对应的类类型。
- 重载运算符在某些运算符上的运算顺序和/或断路属性将会与内置运算符有所区别

相同：
都具有相同或类似的含义。

## 2 [Sales_data](Sales_data_8.h)

## 3

```c++
a. "cobble" == "stone" // 都不是
b. svec1[0] == svec2[0] // string
c. svec1 == svec2 // vector
d. svec1[0] == "stone" // string
```

## 4

a. 双目，不必是类成员。 
b. 会修改左测值，需要是类成员。  
c. 会修改左侧 or 右侧的值，需要是类成员。  
d. 成员访问，需要是类成员。  
e. 双目，不必是类成员。  
f. 双目，不必是类成员。  
g. 双目，不必是类成员。  
h. 需要访问成员，需要是类成员。

## 5

以 [Date](../07-Classes/README.md#42) 为例，可以为其添加一个比较是否相等的函数。
```c++
bool operator==(const Date &lhs, const Date &rhs) {
    if (lhs._year == rhs._year && lhs._month == rhs._month && lhs._day == rhs._day)
        return true;
    return false;
}
```

## 6

[2](#2-sales_data) 已实现

## [7](7.cpp) | [String](String_5.h)

## [8](8.cpp) | [Date](Date_1.h)

## 9

[2](#2-sales_data) 已实现

## 10

a. 输入将没有任何问题，将会生成新的对象。  
b. 在最后一个输入 double 时，流会标记上一个错误，在 `if` 判断时返回 `false`，还原输入的 `item`。

## 11

如果中间出现了输入错误，则后面的值将全为默认值。不会发生什么情况。

## 12 [Date](Date_2.h)

## 13

应该没有了。

## 14

减少复制的次数。

reference: [SO](https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the)

## 15

不应该，两个日期无法相加。

## 16 [StrBlob](StrBlob_5.h) | [StrBlobPtr](StrBlobPtr_2.h) | [StrVec](StrVec_5.h) | [String](String_6.h)

## 17 [Date](Date_3.h)

应该有。

## 18 [StrBlob](StrBlob_6.h) | [StrBlobPtr](StrBlobPtr_3.h) | [StrVec](StrVec_6.h) | [String](String_7.h)

## 19 [Date](Date_4.h)

应该有。

## 20

[2](#2-sales_data) 已实现

## 21 [Sales_data](Sales_data_9.h)

均会产生一个非必要的零时变量。

## 22 [Sales_data](Sales_data_10.h)

## 23 [StrVec](StrVec_7.h)

## 24 [Date](Date_5.h)

应该有。

## 25 

否。（可以实现一个日期的加减，待填坑）

## 26 [StrBlob](StrBlob_7.h) | [StrBlobPtr](StrBlobPtr_4.h) | [StrVec](StrVec_8.h) | [String](String_8.h)

## 27 [StrBlobPtr](StrBlobPtr_5.h)

## 28 [StrBlobPtr](StrBlobPtr_6.h)

## 29

因为自增自减会修改其自身的值，所以未定义为 `const` 的。

## 30 [StrBlobPtr](StrBlobPtr_7.h) | [ConstStrBlobPtr](ConstStrBlobPtr_1.h)

## 31

其生成的拷贝构造、赋值运算符及析构函数已经可以满足需要。没有手动动态分配的内存，不需要手动释放空间。

## 32 [StrBlobPtrPointer](StrBlobPtrPointer_1.h)

## 33

和内置的一样，最多支持 256 个。[SO](https://stackoverflow.com/questions/21211889/how-many-operands-may-an-overloaded-function-call-operator-take)

## 34 [IfThenElse](IfThenElse_1.h)

## 35 [PrintString](InputString_1.h)

## [36](36.cpp)

## [37](37.cpp)

## [38](38.cpp) | [CheckStringSize](CheckStringSize_1.h)

似乎用不到类，可以直接用 `vector` 统计，下一题会用到。

## [39](39.cpp) | [CheckStringSize](CheckStringSize_2.h)

## [40](40.cpp) 

## 41

写类繁碎复杂，还需要命名，使用 `lambda` 更加简洁自然。

过于复杂的 `lambda` 会改用类，较为简单的操作都可以考虑 `lambda`。


## 42

```c++
a. std::count_if(vec.cbegin, vec.cend, std::bind(std::greater<int>(), _1, 1024));
b. std::find_if(vec.cbegin, vec.cend, std::bind(std::not_equal_tp<std::string>(), _1, "pooh"));
c. std::transform(vec.cbegin, vec.cend, std::bind(std::multiplies<int>(), _1, 2));
```

## [43](43.cpp)

## [44](44.cpp)

## [45](45.cpp) | [Sales_data](Sales_data_11.h)

## 46

不应该，意义不明。应该声明为 `explicit` 的。

## 47

`operator const int()` <del>返回的是一个 const 值，</del>毫无意义，会被忽略，`operator int() const` 不会修改对象的值。

## 48

`Date` 类型应该不需要 `bool`，若要声明，也应当使用 `explicit` 的。

## 49 [Date](Date_6.h)

## [50](50.cpp)

```c++
int ex1 = ldObj; // 二义性，不可
float ex2 = ldObj; // 精确匹配，可
```

## [51](51.cpp)

会调用 `void calc(int);` 因为类的类型转换优先级是最低的。

## [52](52.cpp)

```c++
ld = si + ld; // 二义性
ld = ld + si; // 用 LongDouble operator+(const SmallInt &);
```

## [53](53.cpp)

会导致二义性，和内置的冲突。

修改：
```c++
SmallInt s1;
double d = s1 + SamllInt(3.14);
// 或
double d = static_cast<int>(s1) + 3.14;
```

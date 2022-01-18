# 第 5 章 语句

## 5-1

```C++
; // 空语句
```

> 在语法上需要一条语句而逻辑上不需要

## 5-2

```C++
{ } // 块
```

> 语法上需要一条语句，但逻辑上需要多条语句。

## 5-3

```C++
while (val <= 10)
    sum += val, ++val;
```

显然降低了阅读性

## 5-4

a. `iter` 没有初始化就比较了，修改后：
```C++
string::iterator iter = s.begin(); // 外部声明并初始化
while (iter != s.end()) { /* ... */ }
```

b. 在外部使用变量，修改后
```C++
bool status; // 于外部声明
while (bool status = find(word)) { /* ... */ }
if (!status) { /* ... */ }
```

## [5-5](5.cpp)

## [5-6](6.cpp)

## 5-7

```C++
a.  if (ival1 != ival2)
        ival1 = ival2; // 漏了分号
    else ival1 = ival2 = 0;
b.  if (ival < minval) {
        minval = ival;
        occurs = 1;
    } // 漏了花括号
c.  if (int ival = get_value())
        cout << "ival = " << ival << endl;
    else if (!ival) // 作用域
        cout << "ival = 0\n";
d.  if (ival == 0) // 判等
        ival = get_value();
```

## 5-8
例子：
```C++
if (grade % 10 >= 3)
    if (grade %10 > 7)
        lettergrade += "+";
else // 这个 else 同第二个 if 匹配
    lettergrade += "-";
```
就近原则。

## [5-9](9.cpp)

## [5-10](10.cpp)

## [5-11](11.cpp)

## [5-12](12.cpp)

## 5-13
错因：
```C++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        // 少了 break，注意这里说的是编程错误，不是编译错误
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size() - 1; // 尝试使用未声明的变量
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9: // 不支持此中写法，修改为 C++ 写法
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival = 512, jval = 1024, kval =4 096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival: // case 必须是个常量
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```


改正
```C++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default: iouCnt++; break;
    }
(b) unsigned index = some_value();
    int ix; // 修改：提前声明
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 10:
            evencnt++;
            break;
    }
(d) // unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case 512:
            bufsize = 512 * sizeof(int);
            break;
        case 1024:
            bufsize = 1024 * sizeof(int);
            break;
        case 4096:
            bufsize = 4096 * sizeof(int);
            break;
    }
```
## [5-14](14.cpp)

## 5-15

错因：
```C++
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz) // 尝试使用 for 循环体内定义的变量
    // . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ } // 初始化为空，但语法要求必须得有个空语句占位
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ } // 这样会结束么？
```
改正
```C++
(a) int ix;
    for (ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (; ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ } // 去除 sz 的自增
```
## [5-15](15.cpp)

我倾向 `while`，因为其在某些情况下更加简练且易读。

## [5-16](16.cpp)

## 5-17

错误：
```C++
(a) do // 输入两个数并输出他们的和，输出一个不为
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin); // 缺少花括号
(b) do {
        // . . .
    } while (int ival = get_response()); // 尝试在 do...while 条件内创建变量
(c) do {
        int ival = get_response();
    } while (ival); // 尝试访问尚未定义的变量
```
改正：
```C++
(a) do {
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    } while (cin);
(b) int ival;
    do {
        // . . .
    } while (ival = get_response());
(c) int ival = get_response();
    do {
        ival = get_response();
    } while (ival);
```

## [5-19](19.cpp)

原文是：
> Write a program that uses a do while loop to repetitively request two strings from the user and report which string **is less than** the other.

译文是：
> 挑出较短的那个并输出它。

我暂以译文为准。

## [5-20](20.cpp)

## 5-22

```C++
for (int sz = get_size(); sz <= 0; sz = get_size()) ; // 空语句，这样做似乎意义不大？，因为 sz 于内部定义，退出循环后无法访问，所以要做什么可以在循环体内，若要在外部使用则可在外部声明 sz.

// 例如这样，或许更好
int sz;
while ((sz = get_size()) <= 0) ; // 尝试找到 > 0 的 sz
// 处理 > 0 的 sz
```
## [5-23](23.cpp)

## [5-24](24.cpp)

## [5-25](25.cpp)
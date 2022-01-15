# 第 2 章 变量和基本类型

## 2-6

09 的话，编译器会报错

## 2-7

a. 字符串  
b. 长 `double`  
c. `float`  
d. 长 `double`

## 2-11

a. 定义  
b. 定义  
c. 声明  
## 2-12

a. `double` 关键字  
b. 可  
c. - 不可以  
d. 必须以下划线或字母开头  
e. 可

## 2-13

100

## 2-14

合法，输出：100 45

## 2-15

b 非法，不可以为引用初始化字面值常量  
d 非法，不可以不为引用初始化

## 2-16

a. d = 3.14159  
b. d = i 即 d = 0  
c. i = d 即 i = 0  
d. i = d 即 i = 0

## 2-17

10 10

## 2-19

引用只是别名！指针是地址，另外指针是对象，引用不是，引用可以重新赋值，别名已经赋值不可更改。

## 2-20
将 i 翻一倍，再存回去。

## 2-21

a. 非法，用 `double` 的指针存 `int` 型的地址，类型不匹配。  
b. 非法，用指针存变量值，`i` 没有取地址。  
c. 可

## 2-22

看看 `p` 是不是空指针。  
看看 `p` 所指向的值是 0 或别的数。

## 2-23

~~判断指针是否为空~~  
~~`if (p)` // 是空~~

> No, you can't. Because it would be expensive to maintain meta data about what constitutes a valid pointer and what doesn't, and in C++ you don't pay for what you don't want.

[参照](https://stackoverflow.com/questions/17202570/c-is-it-possible-to-determine-whether-a-pointer-points-to-a-valid-object/17202622#17202622)

## 2-24

`lp` 尝试把一个 `int` 型变量的地址赋值给一个 `long` 型指针是非法的。`void *` 可以接受任何指针类型，所以是合法的。

## 2-25

a. `ip` 是个指针，未初始化的指针，在不知道其声明位置时无法确定其值，`r` 是 `i` 的别名。  
b. `ip` 是个空指针。`i` 是未初始化的 `int` 型变量，值是未知的。  
c. `ip` 是个指针，未初始化。`ip2` 是个未初始化的 `int` 型变量。

## 2-26

a. 没有初始化  
b&c. 合法  
d. `++cnt` 合法，`++sz` 常量不可修改，不合法

## 2-27

a. `&r` 不可用初始化为一个字面量常量  
b ~ e. 合法  
f. 没有这种写法，没有引用常量，引用本身不可修改，所以本身就是常量。此外，必须初始化。  
g. 可以
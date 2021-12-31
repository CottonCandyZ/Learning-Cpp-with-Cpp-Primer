## 略
1-2、1-5、1-14、1-15、1-17

2-1、2-2、2-3、2-5

## 文字性答案

### 1-6

多了分号

### 2-6

09 的话，编译器会报错

### 2-7

a. 字符串
b. 长 double
c. float
d. 长 double

### 2-11

a. 定义
b. 定义
c. 声明

### 2-12

a. double 关键字
b. 可
c. - 不可以
d. 必须以下划线或字母开头
e. 可

### 2-13

100

### 2-14

合法，输出：100 45

### 2-15

b 非法，不可以为引用初始化字面值常量
d 非法，不可以不为引用初始化

### 2-16

a. d = 3.14159
b. d = i 即 d = 0
c. i = d 即 i = 0
d. i = d 即 i = 0

### 2-17

10 10

### 2-19

引用只是别名！指针是地址，另外指针是对象，引用不是，引用可以重新赋值，别名已经赋值不可更改。

### 2-20
将 i 翻一倍，再存回去。

### 2-21

a. 非法，用 double 的指针存 int 型的地址，类型不匹配。
b. 非法，用指针存变量值，i 没有取地址
c. 可

### 2-22

看看 p 是不是空指针
看看 p 所指向的值是 0 或别的数

### 2-23

~~判断指针是否为空~~

~~if (p) // 是空~~

> No, you can't. Because it would be expensive to maintain meta data about what constitutes a valid pointer and what doesn't, and in C++ you don't pay for what you don't want.

[参照](https://stackoverflow.com/questions/17202570/c-is-it-possible-to-determine-whether-a-pointer-points-to-a-valid-object/17202622#17202622)

# 第 15 章 面向对象程序设计

## 1

用于完成继承类的动态绑定。

## 2

派生类不可以访问 `private` 成员，但可以访问 `protected` 成员。

## 3 [Quote](Quote_1.h)

## 4

```c++
class Base { ... };
(a) class Derived : public Derived { ... }; // 不正确，不能继承自身
(b) class Derived : private Base { ... }; // 正确
(c) class Derived : public Base; // 不正确，其细节必须与其一起出现
```

## 5 [Bulk_quote](Bulk_quote_1.h)

## [6](6.cpp)

## 7 [Limit_quote](Limit_quote_1.h)

## 8

静态类型：由 `static` 修饰，编译时确定类型。

动态类型：编译时并不知道其类型，在运行时知道其类型，对于引用和指针，其动态类型和静态类型可能不一致。

## 9

基类的指针和引用使用派生对象时。基类类型作为其静态类型，派生对象的类型作为其动态类型。

## 10

`std::istream` 作为 `std::ifstream` 的基类，可以完成动态绑定工作。

## 11 [Quote](Quote_2.h) | [Bulk_quote](Bulk_quote_2.h) | [Limit_quote](Limit_quote_2.h)

## 12

可以。这样可以保证后面的函数不再覆盖。对当前类和继承类的要求的这两个需求并不冲突。

## 13

```c++
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; } // 这里会导致递归
private:
    int i;
};
```

将会递归的哪一行重写成：
```c++
    void print(ostream &os) { base::print(os); os << " " << i; } // 增加 base 限定访问域
```

## 14

```c++
base bobj; base *bp1 = &bobj; base &br1 = bobj;
derived dobj; base *bp2 = &dobj; base &br2 = dobj;
(a) bobj.print();   // base::print()
(b) dobj.print();   // derived::print()
(c) bp1->name();    // base::name()
(d) bp2->name();    // base::name()
(e) br1.print();    // base::print()
(f) br2.print();    // derived::print()
```

## 15 [Disc_quote](Disc_quote_1.h) | [Bulk_quote](Bulk_quote_3.h)

## 16 [Limit_quote](Limit_quote_3.h)]

## [17](17.cpp)

```
Variable type 'Disc_quote' is an abstract class
```

## 18

```c++
Base *p = &d1;  // d1 的类型是 Pub_Derv                 —— 可
p = &d2;        // d2 的类型是 Priv_Derv                —— 不可，p 无法访问继承的成员
p = &d3;        // d3 的类型是 Prot_Derv                —— 不可，原因同上
p = &dd1;       // dd1 的类型是 Derived_from_Public     —— 可
p = &dd2;       // dd2 的类型是 Derived_from_Private    —— 不可
p = &dd3;       // dd3 的类型是 Derived_from_Protected  —— 不可
```

## 19

每个都可以，在成员函数内，其可以访问其成员。

## [20](20.cpp)

## [21](21.cpp) [Shape](Shape_1.h)

## 22

见上一题。

## [23](23.cpp)

```c++
Base bobj; D1 d1obj; D2 d2obj;
Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
bp1->fcn(); // Base::fcn()
bp2->fcn(); // D1::fcn()
bp3->fcn(); // D2::fcn()
D1 *d1p = &d1obj; D2 *d2p = &d2obj;
d1p->f2(); // D1::f2()
d2p->f2(); // D2::f2()
```

## 24

一个基类总是需要虚析构函数。需要声明成 `virtual` 供后续的派生类重写覆盖它。

## [25](25.cpp) | [Disc_quote](Disc_quote_2.h) | [Bulk_quote](Bulk_quote_4.h)

只有通过父类定义了的默认构造函数，子类才可以定义默认构造函数，若尝试使用`default` 则会被隐式的声明为 `deleted`。  
`Bulk_quote` 将无法使用默认构造函数，声明空对象时将会报错。

## [26](26.cpp) | [Quote](Quote_3.h) | [Bulk_quote](Bulk_quote_5.h)

## 27 [Bulk_quote](Bulk_quote_6.h)

## [28](28.cpp)

## [29](29.cpp)

28 的版本调用的是 `Quote` 的成员函数 `net_price`，而 29 调用的是带折扣的 `Bulk_quote` 的版本。

## [30](30.cpp) [Basket](Basket_1.h) | [Quote](Quote_4.h) | [Bulk_quote](Bulk_quote_7.h)

## 31

```
a. WordQuery -> NotQuery -> AndQuery -> OrQuery
b. WordQuery -> NotQuery -> AndQuery -> OrQuery
c. WordQuery -> AndQuery -> OrQuery
```

## 32

`Query` 只是拥有一个指向 `Query_base` 的 `shared_ptr` 指针，因此其拷贝、赋值、销毁时，其引用计数会发生变化，
其变化的方式与操作 `shared_ptr` 时发生的变化相同（即在复制时引用计数 +1，移动时不变，销毁时 -1）。

## 33

`Query_base` 使用合成的版本，它作为一个抽象类，当它在执行这些操作时，使用的是他的派生类。

## 34

```
a. WordQuery -> Query -> \
                           -> BinaryQuery -> AndQuery -> Query(private) -> --------------------> \ 
   WordQuery -> Query -> /                                                                        -> BinaryQuery -> OrQuery -> Query(private)
                                                                 --------> WordQuery -> Query -> /
b. Query -> BinaryQuery -> Query -> WordQuery
                  \
                   ------> Query -> BinaryQuery -> Query -> WordQuery
                                         \
                                          -------> Query -> WordQuery
c. Query -> OrQuery -> Query -> WordQuery 
               \
                -----> AndQuery -> Query -> WordQuery
                           \
                            -----> Query -> WordQuery
```

## 35 [Query](35/Query.h) | [Query_base](35/Query_base.h)

## [36](36)

## [37](37)

主要修改了：[Query_base](37/Query_base.h) | [BinaryQuery](37/BinaryQuery.h) | [AndQuery](37/AndQuery.h) | 
[NotQuery](37/NotQuery.h) | [OrQuery](37/OrQuery.h)

其相当于不再通过 `Query` 去调用相应的函数，因此需要把直接调用的他们作为 `Query_base` 的友元。（这可能是一种不太好的设计方式，因为其造成了某种跨越，变得有点难维护）

## 38

三个都是不合法的，主要有以下两点：
- 他们均没有对应 `share_ptr<Query_base>` 的构造函数，且都不是 `Query` 的派生类，所以哪怕使用强制类型转换也无法实现这样的转换。
- 他们的成员函数外部不可访问，转化自然没有意义。

## [39](15.9)

结果：
```
Executing Query for: ((fiery & bird) | wind)
((fiery & bird) | wind) occurs 2 times
	(line 2) Her Daddy says when the wind blows
	(line 4) like a fiery bird in flight.
```

## 40

按照正常的并集结果，即 `rhs` 为空时，并集结果就是 `lhs`，同理 `lhs` 为空时，结果为 `rhs`。若两个都为空集，则结果为空。

## [41](41)

## 42

仅给出可能需要修改的地方，留个坑  
a. 在 `TextQuery` 中对读入的文件按句子分组，然后实现与前面一致。  
b. 暂未想到较好的解决方案。  
c. 可以前置过滤，即在 `TextQuery` 中剔除部分行。也可以后置，但性能肯定不如前置，即在 `QueryResult` 增加个成员函数用于过滤输出。
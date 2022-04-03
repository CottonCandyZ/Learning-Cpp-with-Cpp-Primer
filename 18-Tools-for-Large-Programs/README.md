# 第 18 章 用于大型程序的工具

## 21

```c++
a. class CADVehicle : public CAD, Vehicle { ... }; // 无错误，但是注意 Vehicle 是以 private 继承的
b. class DblList : public List, public List { ... }; // 错误，重复继承
c. class iostream : public istream, public ostream { ... }; // 无错误
```

## 22

```
A -> B -> C -> X -> Y -> Z -> MI
```

## 23

```c++
a. X *px = pd; // allowed
b. A *pa = pd; // allowed
c. B *pb = pd; // allowed
d. C *pc = pd; // allowed
```

## 24

```c++
ZooAnimal *pz = new Panda("ying_yang");
pb->print();    // 正确：Panda::print()
pb->cuddle();   // 错误：不属于 ZooAnimal 的接口
pb->highlght(); // 错误：不属于 ZooAnimal 的接口
delete pb;      // 正确：Panda::~Panda()
```

## 25

```c++
a. pb1->print(); // MI::print()
b. pd1->print(); // MI::print()
c. pd2->print(); // MI::print()
d. delete pb2;   // Base1 -> D1 -> Base2 -> D2 -> MI
e. delete pb1;   // Base1 -> D1 -> Base2 -> D2 -> MI
f. delete pb2;   // Base1 -> D1 -> Base2 -> D2 -> MI
```

## 26

二义性调用，`Base1::print(int) const` 和 `Base2::print(double) const` 都是可以的。

修改方式：显式重载。

```c++
struct MI : public Derived, public Base2 {
    void print(std::vector<double>);
    void print(int i) const {
        Base1::print(i);
    }
protected:
    int *ival;
    std::vector<double> dvec;
};
```

## 27

a. `Base1::ival, Base1::dval, Base1::cval, Base2::fval, Derived::sval, Derived::dval, MI::ival, MI::dvec, ival, dval(double)(被覆盖), cval, dval(int)`
和 `Base1::print(int) const, Base2::print(double) const, Derived::print(std::string) const, MI::print(std::vector<double>)`  
b. 如果不使用作用域运算符，那么 `Base1::dval, Derived::dval` 等显然是。  
c. `davl = Base1::dval + Derived::dval;`  
d. `Base2::fval = MI::dvec.back();`  
e. `Derived::sval.insert(0, 1, Base1::cval);`

## 28

```c++
struct Base {
    void bar(int); // 需要，会被 Derived1::bar(char) 覆盖
protected:
    int ival; // 需要，会被 Derived2::ival 覆盖
};

struct Derived1 : virtual public Base {
    void bar(char); // 不需要

    void foo(char); // 需要

protected:
    char cval; // 需要
};

struct Derived2 : virtual public Base {
    void foo(int); // 需要

protected:
    int ival; // 不需要
    char cval; // 需要
};

class VMI : public Derived1, public Derived2 { };
```

## 29

a. 构造函数：`Class -> Base -> D1 -> D2 -> MI -> Class -> Final`，析构函数：`Final -> Class -> MI -> D2 -> D1 -> Base -> Class`。  
b. 一个 Base，两个 Class。  
c.a. 错误，尝试用派生类的指针指向基类  
c.b. 不可以，会有二义性  
c.c. 同 c.a  
c.d. 可以

## [30](30.h)


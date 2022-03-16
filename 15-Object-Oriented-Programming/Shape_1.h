//
// Created by CottonCandyZ on 3/14/22.
//

#ifndef C__PRIMER_SHAPE_1_H
#define C__PRIMER_SHAPE_1_H

#include <string>

static const double PI = 3.13159;

class Shape {
public:
    virtual std::string shape_name() const = 0;

    virtual ~Shape() {};
};

class Shape_2D : public Shape {
public:
    Shape_2D() = default;

    Shape_2D(double _x, double _y) : x(_x), y(_y) {}

    virtual double area() const = 0;

    ~Shape_2D() override {}

protected:
    double x = 0.f;
    double y = 0.f;
};

class Shape_3D : public Shape {
public:
    Shape_3D() = default;

    Shape_3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    virtual double volume() const = 0;

    ~Shape_3D() override {}

protected:
    double x = 0;
    double y = 0;
    double z = 0;
};

class Box : public Shape_3D {// 方格，原文是 box 不知道为什么中文就被翻译成了方格？
public:
    Box() = default;

    explicit Box(double width) : half_len_x(width / 2), half_len_y(width / 2),
                                                          half_len_z(width / 2) {}

    // xyz对应其中心坐标
    Box(double _x, double _y, double _z, double _half_len_x, double _half_len_y, double _half_len_z) :
            Shape_3D(_x, _y, _z), half_len_x(_half_len_x), half_len_y(_half_len_y), half_len_z(_half_len_z) {}


    std::string shape_name() const override {
        return "Box";
    }


    double volume() const override {
        return half_len_x * half_len_y * half_len_z * 8;
    }

    ~Box() override {}

private:
    // 这里按照右手系的话，x 对应深度，y 对应宽度，z 对应高度
    double half_len_x = 0.5;
    double half_len_y = 0.5;
    double half_len_z = 0.5;
};

class Circle : public Shape_2D {
public:
    Circle() = default;

    explicit Circle(double _radius) : radius(_radius) {}

    Circle(double _x, double _y, double _radius) : Shape_2D(_x, _y), radius(_radius) {}

    std::string shape_name() const override {
        return "Circle";
    }

    double area() const override { return PI * radius * radius; }

    double circumference() const { return PI * 2 * radius; }

    ~Circle() override {}


private:
    double radius = 1;
};


class Sphere : public Shape_3D {
public:
    Sphere() = default;

    explicit Sphere(double _radius) : radius(_radius) {}

    Sphere(double _x, double _y, double _z, double _radius) : Shape_3D(_x, _y, _z), radius(_radius) {}

    std::string shape_name() const override { return "Sphere"; }

    double volume() const override { return 4 * PI * radius * radius * radius / 3; }

    double surface_area() { return 4 * PI * radius * radius; }

    ~Sphere() override {}

private:
    double radius = 1;
};

class Cone : public Shape_3D {
public:
    Cone() = default;

    Cone(double _radius, double _height) : radius(_radius), height(_height) {}

    Cone(double _x, double _y, double _z, double _radius, double _height) : Shape_3D(_x, _y, _z),
                                                                            radius(_radius), height(_height) {}

    std::string shape_name() const override { return "Cone"; }

    double volume() const override { return PI * radius * radius * height / 3; }

    ~Cone() override {}

private:
    double radius;
    double height;

};


#endif //C__PRIMER_SHAPE_1_H

//
// Created by CottonCandyZ on 3/15/22.
//

#include <iostream>
#include <vector>
#include "Shape_1.h"

std::ostream &printArea(std::ostream &os, const Shape_2D &shape2D) {
    os << shape2D.shape_name() << " 的面积是：" << shape2D.area();
    return os;
}

std::ostream &printArea(std::ostream &os, const Shape_3D &shape3D) {
    os << shape3D.shape_name() << " 的体积是：" << shape3D.volume();
    return os;
}

int main() {
    Box box(0.5);
    Circle circle(1);
    Sphere sphere(1);
    Cone cone(1, 2);
    printArea(std::cout, circle) << std::endl;
    std::vector<Shape_3D *> shapes_3d{&box, &sphere, &cone};
    std::for_each(shapes_3d.cbegin(), shapes_3d.cend(),
                  [](const Shape_3D *shape) { printArea(std::cout, *shape) << std::endl; });
    return 0;

}
#include <iostream>
#include <cmath>
#include "rectangle.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape{
    public:
        Triangle() = default;
        Triangle(double a, double b, double c) : _a(a), _b(b), _c(c){};
        void print() const;
        double area() const;

    protected:
        double _a, _b, _c;
};

#endif
#include <iostream>
#include <cmath>
#include "rectangle.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape{
    public:
        Circle() = default;
        explicit Circle(int r) : _r(r){};
        void print() const;
        double area() const;

    protected:
        int _r;
};

#endif
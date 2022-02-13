#include <iostream>

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Shape{
    public:
        Shape() = default;
        virtual ~Shape(){};

        virtual void print() const{std::cout<<"SHAPE";}
        friend void print(const Shape &sh);
        void print(std::ostream &str) const;

        virtual double area() const{return 0.0;}
};

class Rectangle : public Shape{
    public:
        Rectangle() = default;
        Rectangle(int a, int b) : _a(a), _b(b){};
        void print() const;
        double area() const;

    protected:
        int _a, _b;
};

#endif
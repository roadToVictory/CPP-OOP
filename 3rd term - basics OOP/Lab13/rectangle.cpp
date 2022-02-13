#include "rectangle.h"

void print(const Shape &sh){
    sh.print();
}

void Shape::print(std::ostream &str) const{
    print();
}

void Rectangle::print() const{
    std::cout<<"Prostokat o bokach: " <<_a<<", "<<_b<<std::endl;
}

double Rectangle::area() const{
    return _a*_b;
}
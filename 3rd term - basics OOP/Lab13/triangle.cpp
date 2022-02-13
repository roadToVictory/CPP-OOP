#include "triangle.h"

void Triangle::print() const{
    std::cout<<"Trojkat o bokach: " <<_a<<", "<<_b<<", "<<_c<<std::endl;
}

double Triangle::area() const{
    double x = (_a+_b+_c)/2;
    return (sqrt(x*(x-_a)*(x-_b)*(x-_c)));
    //sqrt(x(x-a)(x-b)(x-c)) 
}
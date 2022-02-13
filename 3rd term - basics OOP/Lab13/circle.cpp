#include "circle.h"

void Circle::print() const{
    std::cout<<"Kolo o promieniu: " <<_r<<std::endl;
}

double Circle::area() const{
    return (M_PI*_r*_r);
}
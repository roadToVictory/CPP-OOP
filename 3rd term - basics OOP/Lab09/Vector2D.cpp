#include "Vector2D.h"

int Vector2D::count=0;

Vector2D::Vector2D(const Vector2D &vector){
    this->_nazwa = vector._nazwa;
    this->_x = vector._x;
    this->_y = vector._y;
    count++;
    std::cout<<"--- kopiowanie "<<_nazwa<<"=("<<_x<<", "<<_y<<")"<<std::endl;
    //--- kopiowanie V2=(3.4641, 2)
}

/*Vector2D::Vector2D(Vector2D &&vector){
    count++;
    std::cout<<"--- przenoszenie "<<vector._nazwa<<"=("<<vector._x<<", "<<vector._y<<")"<<std::endl;

    _nazwa = vector._nazwa;
    _x = vector._x;
    _y = vector._y;

    vector._nazwa = "";
    vector._x = 0.0;
    vector._y = 0.0;
}*/

Vector2D::Vector2D(Vector2D &&vector): _nazwa(std::move(vector._nazwa)),
                                        _x(std::exchange(vector._x, 0.0)),
                                        _y(std::exchange(vector._y, 0.0)) {
    count++;
    std::cout<<"--- przenoszenie "<<_nazwa<<"=("<<_x<<", "<<_y<<")"<<std::endl;
}

Vector2D Vector2D::fromCarthesian(std::string name, double x, double y){
    Vector2D temp;
    temp._nazwa = name;
    temp._x = x;
    temp._y = y;
    return temp;
}

Vector2D Vector2D::fromCarthesian(double x, double y){
    Vector2D temp;
    temp._nazwa = "Vx";
    temp._x = x;
    temp._y = y;
    return temp;
}

Vector2D Vector2D::fromPolar(std::string name, double r, double phi){
    Vector2D temp;
    temp._nazwa = name;
    temp._x = r*cos((2*M_PI*phi)/360.0);
    temp._y = r*sin((2*M_PI*phi)/360.0);
    return temp;
}

void Vector2D::print(const std::string nazwa) const{
    std::cout<<nazwa<<_nazwa<<"=("<<_x<<", "<<_y<<")"<<std::endl;
}

double Vector2D::dot(const Vector2D &vector) const{
    return (_x*vector._x + _y*vector._y);
}

Vector2D Vector2D::add(const Vector2D &vector) const{
    Vector2D temp;
    temp._x = _x + vector._x;
    temp._y = _y + vector._y;
    return temp;
}
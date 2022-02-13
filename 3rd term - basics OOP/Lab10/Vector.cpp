#include "Vector.h"

Vector::Vector(int size){
    _wektor = new double[size];
    _rozmiar = size;

    for(int i=0; i<size;i++)
        _wektor[i] = 0;
}

Vector::~Vector(){
    if(_wektor !=nullptr)
        delete [] _wektor;
}

Vector::Vector(const Vector &vec){
    _rozmiar = vec._rozmiar;
    _wektor = new double[_rozmiar];

    for(int i=0; i<_rozmiar;i++)
        _wektor[i] = vec._wektor[i];
}

Vector::Vector(Vector &&vec): _rozmiar(std::move(vec._rozmiar)), _wektor(std::move(vec._wektor)){
    vec._wektor = nullptr;
    vec._rozmiar = 0;
}

double& Vector::at(int wartosc){
    return _wektor[wartosc];
}

void Vector::print(const std::string text) const{
    std::cout<<text<<"(";
    
    for(int i=0; i<_rozmiar; i++){        
        i+1 < _rozmiar ? std::cout<<_wektor[i]<<", " : std::cout<<_wektor[i];
    }
    std::cout<<")"<<std::endl;
   // v1 = (4, 2, 0)
}

double Vector::dot(const Vector &vec1, const Vector &vec2){
    if(vec1._rozmiar == vec2._rozmiar){
        double wynik=0.0;
        for(int i=0; i<vec1._rozmiar; i++)
            wynik += vec1._wektor[i] * *(vec2._wektor+i);
        return wynik;
    }
    else return 0;
}

double Vector::norm() const{
    return sqrt(dot(*this, *this));
}

Vector::operator double() const{
    return (double)norm();
}

Vector Vector::sum(const Vector &vec1, const Vector &vec2){
    Vector temp(vec1._rozmiar);
    for(int i=0; i<vec2._rozmiar; i++)
        temp._wektor[i] = vec1._wektor[i] + vec2._wektor[i];
    return temp;
}

Vector Vector::sum(const Vector &vec1, double n){
    Vector temp(vec1._rozmiar);
    for(int i=0; i<vec1._rozmiar; i++)
        temp._wektor[i] = vec1._wektor[i] + n;

    return temp;
}
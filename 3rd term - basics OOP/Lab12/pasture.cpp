#include "pasture.h"

Pasture::Pasture(double a, int ilosc) : _pow(a*a), _ilosc(ilosc){
    _pas = new bool[_ilosc];
    for(int i=0; i<_ilosc; i++)
        _pas[i] = rand()%2;
}

std::ostream& operator <<(std::ostream &strumien, const Pasture &pas){
    std::cout<<"Pole: "<<pas._pow<<", owce: ";
    for(int i=0; i<pas._ilosc; i++)
        std::cout<< pas._pas[i]<<" ";
    std::cout<<std::endl;
    return strumien;
}

Pasture::Pasture(const Pasture &pas): _pow(pas._pow), _ilosc(pas._ilosc){  
    _pas = new bool[_ilosc];
    for(int i=0; i<_ilosc;i++)
        _pas[i] = pas._pas[i];
}

Pasture::Pasture(Pasture &&pas) : _pow(std::move(pas._pow)), _ilosc(std::move(pas._ilosc)), _pas(std::move(pas._pas)){  //_pas(std::exchange(pas._pas, nullptr))
    pas._ilosc =0;
    pas._pow=0;
    pas._pas = nullptr;
}

Pasture::~Pasture(){
    if(_pas!=nullptr)
        delete []_pas;
}

Pasture& Pasture::operator =(const Pasture &pas){
    if(this==&pas)
        return *this;
    
    _pow = pas._pow;
    _ilosc = pas._ilosc;

    if(_pas !=nullptr)
        delete[] _pas;
    
    _pas = new bool[_ilosc];
    for(int i=0; i<_ilosc; i++)
        _pas[i] = pas._pas[i];
    
    return *this;
}

Pasture Pasture::operator +(const Pasture &pas) const{
    Pasture temp;
    temp._ilosc=_ilosc+pas._ilosc;
    temp._pow = _pow + pas._pow;
    temp._pas = new bool[temp._ilosc];
    for(int i=0; i<_ilosc; i++)
        temp._pas[i] = _pas[i];
    for(int i=0; i<pas._ilosc;i++)
        temp._pas[_ilosc+i] = pas._pas[i];
    return temp;
}

Pasture& Pasture::operator *=(const double a){
    _pow *= a;
    return *this; 
}

bool Pasture::operator()(const Pasture &pas, const Pasture &pas1) const{
    if(pas._pow >= pas1._pow)
    return true;
  else return false;
}

Pasture operator*(const double a, const Pasture &pas){
    Pasture temp = pas;
    temp*=a;
    return temp;
}

Pasture operator*(const Pasture &pas, const double a){
    Pasture temp = pas;
    temp*=a;
    return temp;
}
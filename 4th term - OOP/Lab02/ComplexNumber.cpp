#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double re, double im){
  _re = re;
  _im = im;
}

ComplexNumber::ComplexNumber(const ComplexNumber& n){
  this->_re=n._re;
  this->_im = n._im;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &n) const{
  ComplexNumber temp;
  temp._re = _re + n._re;
  temp._im = _im+n._im;
  return temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &n) const{
  ComplexNumber temp;
  temp._re = _re - n._re;
  temp._im = _im-n._im;
  return temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &n) const{
  ComplexNumber temp;
  temp._re =_re*n._re - (_im*n._im);
  temp._im=_re*n._im + _im*n._re;
  return temp;

  //(A1 + i*A2)*(B1 + i*B2) = A1*B1 - A2*B2 + i*(A1*B2 + A2*B1)
}

ComplexNumber& ComplexNumber::operator*=(int liczba){
  this->_re = _re*liczba;
  this->_im = _im*liczba;
  return *this;
}

ComplexNumber& ComplexNumber::operator++(){
  this->_re+=1;
  return *this;
}

ComplexNumber ComplexNumber::operator++(const int liczba){
  ComplexNumber temp=*this;
  this->_re++;
  return temp;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber &n){
  if(this==&n)
    return *this;
  
  _im=0; _re=0;
  _im=n._im;
  _re=n._re;
  return *this;
}

double& ComplexNumber::operator[](int n){
  if(n)
    return _im;
  else return _re;
}

 bool ComplexNumber::operator>(const ComplexNumber &n) const{
   if(_re*_re+_im*_im>n._re*n._re+n._im*n._im)
    return 1;
  else return 0;
 }

std::ostream& operator<<(std::ostream& str, const ComplexNumber &n){
  return str<<n._re<<" + " << n._im <<"i";
}

ComplexNumber operator+(double liczba ,const ComplexNumber &n){
  return ComplexNumber(liczba+n._re, n._im);
}
#include "Functions.h"

double Asin::licz(double x) const{
  if( pow(x,2)>1 )
    throw WrongArgument();
  else return std::asin(x);
}

double Log10::licz(double x) const{
  if( x<0 )
    throw WrongArgument();
  else return std::log10(x);
}

double DivideBy::licz(double x) const{
  if(!x)
    throw DivisionByZero();
  else return _x/x;
}
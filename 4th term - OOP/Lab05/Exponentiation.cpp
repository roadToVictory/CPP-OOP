#include "Exponentiation.h"

void Exponentiation::print() const{
  std::cout<<" "<<_x<<" ^ "<<_pot<<" ";
}

double Exponentiation::eval() const{
  return pow(_x, _pot);
}

#include "SumOfElements.h"

void SumOfElements::print() const{
  for(int i=0; i<_n; i++){
    (i+1)<_n ? std::cout<<" "<<_tablica[i]<<" + " : std::cout<<_tablica[i];
  }
}
//=== 1 + 3.2 + 5 + 11 ===

double SumOfElements::eval() const{
  double suma=0.0;

  for(int i=0; i<_n; i++)
    suma+=_tablica[i];
  return suma;
}
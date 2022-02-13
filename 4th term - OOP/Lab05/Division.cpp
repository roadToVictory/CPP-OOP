#include "Division.h"

void Division::print() const{
  std::cout<<" "<<_x<<" / " <<_y<<" ";
}

double Division::eval() const{
  return _x/_y;
}
#include "Operation.h"

void operator >>=(const std::string &text, const Operation &oper){
  std::cout<<text;
  oper.print(); //wywolywana jest metoda print() z klasy zgodnej z typem oper
  std::cout<<text<<std::endl;
}
#pragma once
#include "Functions.h"

/**
* Klasa SecureCalc do bezpiecznego obliczania wartosci funkcji
*/
class SecureCalc{
  public:
  //funkcja statyczna obliczajaca wartosc funkcji
    static void run(const Functions& fun, double x);
};

void SecureCalc::run(const Functions& fun, double x){
  std::cout<<"Obliczamy: " << fun.Name()<<"("<<x<<")"<<std::endl;
  try{
    double tmp = fun.licz(x);
    std::cout<<"-> Wynik: " << tmp<<std::endl;
  }
  catch(WrongArgument &wr){
    std::cout<<"Error: wrong argument of "<<fun.Name()<<std::endl;
  }
  catch(DivisionByZero &wr){
    std::cout<<"Error: divide by zero!"<<std::endl;
  }
  catch(...){
     std::cout<<"Another!"<<std::endl;
  }
}
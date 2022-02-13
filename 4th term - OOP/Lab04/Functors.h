#pragma once
#include <iostream>

/*klasa reprezentujaca funktor sprawdzajacy podzielnosc przez zadana liczbe*/
class DivisibleBy{
  public:
  //konstruktor z parametrem okreslajacym podzielnosc 
    DivisibleBy(int x): _div(x){}
  
  //przeladowanie operatora () do sprawdzania podzielnosci
    bool operator()(int x){
      return (x%_div)? false : true;
    }

  private:
    int _div;
};


/*klasa reprezentujaca funktor sprawdzajacy czy dana liczba jest wieksza od innej*/
class GreaterThan{
  public:
  //konstruktor z parametrem okreslajacym podzielnosc 
    GreaterThan(int x): _greater(x){}
  
  //przeladowanie operatora () do sprawdzania podzielnosci
    bool operator()(int x){
      return (x>_greater);
    }

  private:
    int _greater;
};
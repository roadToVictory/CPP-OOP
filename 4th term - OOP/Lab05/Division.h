#pragma once

#include "Operation.h"

///klasa wykonujaca dzielenie dziedziczaca publicznie po Operation
class Division : public Operation{
  public:
  /**
  konstruktor tworzacy nowy obiekt
    @param x liczba do podzielenia
    @param y liczba przez ktora dzielimy
  */
    Division(double x, double y): _x(x), _y(y){}

  /**
   funkcja do wypisywania
  */ 
    void print() const override; //zastosowanie slowa kluczowego 'override' pomaga zweryfikowac czy klasa bazowa posiada metode wirtualna o tej samej nazwie i przyjmowanych parametrach co w klasie pochodnej

  /**
   funkcja do obliczania
   @return obliczona wartosc po podzieleniu
  */ 
    double eval() const override;

  private:
    double _x;
    double _y;
};
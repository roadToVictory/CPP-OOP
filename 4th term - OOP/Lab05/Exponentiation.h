#pragma once
#include "Operation.h"
#include <cmath>


/// Klasa wykonujaca podnoszenie do potegi dziedziczaca publicznie po Operation
class Exponentiation : public Operation{
  public:
  /**
  konstruktor tworzacy nowy obiekt
    @param x podstawa potegi
    @param pot wykladnik potegi
  */
    Exponentiation(double x, double pot): _x(x), _pot(pot){}
  
  /**
   funkcja do wypisywania ze slowem kluczowym override
  */ 
    void print() const override;

  /**
   funkcja do obliczania
   @return obliczona wartosc po podniesieniu do potegi
  */ 
    double eval() const override;

  private:
    double _x;
    double _pot;
};
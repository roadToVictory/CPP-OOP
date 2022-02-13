#pragma once
#include "Operation.h"


///Klasa wykonujaca sumowanie elementow dziedziczaca publicznie po Operation
class SumOfElements : public Operation{
  public:
   /**
    konstruktor tworzacy nowy obiekt
      @param *tablica tablica zawierajaca cyfry
      @param n rozmiar tablicy
  */
    SumOfElements(double *tablica, const int n): _tablica(tablica), _n(n){}

  /**
   funkcja do wypisywania ze slowem kluczowym override
  */ 
    void print() const override;

  /**
   funkcja do obliczania
   @return obliczona wartosc po dodaniu
  */ 
    double eval() const override;

  private:
    double* _tablica;
    int _n;
};
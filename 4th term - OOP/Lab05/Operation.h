#pragma once
#include <string>
#include <iostream>

///Klasa "zbiorcza" zawierajaca wykonywane operacje
class Operation{
  public:
  //destruktor
    virtual ~Operation(){}
  
   /**
    funkcja to wypisywania z podanym stringiem
      @param text napis "separujacy"
      @param oper obiekt klasy Operation
   */
    friend void operator >>=(const std::string &text, const Operation &oper);

    /**
      wirtualna funkcja do wypisywania
    */
    virtual void print() const =0; //slowo kluczone 'virtual' mowi ze metoda ta bedzie 'nadpisywana' w klasach pochodnych ktore dziedzicza po tej klasie(bazowej)
  
    /**
    wirtualna funkcja obliczajaca dana wartosc 
    */
    virtual double eval() const =0;
};
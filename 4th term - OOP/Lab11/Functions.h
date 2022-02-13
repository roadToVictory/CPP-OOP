#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

/**
* Klasa czysto wirtualna
*/
class Functions{
  public:
//wirtualny destruktor
  ~Functions() = default;
//wirtualna funkcja obliczajaca wartosc funkcji
  virtual double licz(double x) const  = 0;
//wirtualna funkcja wypisujaca nazwe 
  virtual std::string Name() const =0;
};

/**
* Klasa reprezentujaca obliczenia funkcji arcus sinus
*/
class Asin : public Functions{
  public:
  //funkcja obliczajaca wartosc funkcji arcsin
    double licz(double x) const override;
  //funkcja wypisujaca nazwe funkcji
    std::string Name() const override{
      return "arcsin";
    }
};

/**
* Klasa reprezentujaca logarytm dziesietny
*/
class Log10 : public Functions{
  public:
  //funkcja obliczajaca wartosc funkcji log10
    double licz(double x) const override;
  //funkcja wypisujaca nazwe funkcji
    std::string Name() const override{
      return "log10";
    }

};

/**
* Klasa reprezentujaca dzielenie 
*/
class DivideBy : public Functions{
  public:
  //funkcja obliczajaca wartosc z dzielenia dwoch liczb 
    DivideBy(double val): _x(val){}
    double licz(double x) const override;
  //funkcja wypisujaca nazwe funkcji
    std::string Name() const override{
      return "DivideBy";
    }

  private:
    double _x;
};

/**
* Klasy reprezentujace wyjątki dziedziczace po klasie std::exception 
*/
class WrongArgument : public std::exception{};
class DivisionByZero : public std::exception{};
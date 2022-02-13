#pragma once

#include "Animal.h"
#include <iostream>


/**
Klasa reprezentujaca owce, dziedziczaca publicznie po klasie Animal
*/
class Sheep: public Animal{
  public:
  //konstruktor
    Sheep(std::string nazwa): Animal(nazwa){}
  //desktuktor
    ~Sheep();
  //funkcja do wypisywania
    void print() const override;
  //funkcja "strzyzaca"
    void shear(){m_ostrzyzona=true;};


  private:
    bool m_ostrzyzona=false;  //tylko owce można strzyc, standardowo/poczatkowo nieostrzyzona 
};



/**
Klasa reprezentujaca krowy, dziedziczaca publicznie po klasie Animal
*/
class Cow : public Animal{
  public:
  //konstruktor
    Cow(std::string nazwa):Animal(nazwa){}
  //desktuktor
    ~Cow();

  //funkcja do wypisywania
    void print() const override;
};


/**
Klasa reprezentujaca konie, dziedziczaca publicznie po klasie Animal
*/
class Horse : public Animal{
public:
  //konstruktor
    Horse(std::string nazwa):Animal(nazwa){}
  //desktuktor
    ~Horse();
  //funkcja do wypisywania
    void print() const override;
  
};
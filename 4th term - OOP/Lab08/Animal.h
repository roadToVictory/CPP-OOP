#pragma once

#include <string>

/**
Klasa reprezentująca zwierzeta na pastwisku
*/
class Animal{
  public:
  //konstruktor tworzacy obiekt typu Animal
    explicit Animal(const std::string nazwa): m_nazwa(nazwa){}
  //destruktor wirtualny
    virtual ~Animal(){}
  //funkcja do wypisywania informacji o zwierzeniu
    virtual void print() const =0;
  //funkcja zwracajaca nazwe zwierzecia
    std::string name() const{return m_nazwa;}
  

  protected:
    std::string m_nazwa; //nazwa zwierzecia
};


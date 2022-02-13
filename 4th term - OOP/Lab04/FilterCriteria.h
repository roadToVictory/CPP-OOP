#pragma once
#include <iostream>
#include <functional>
#include <vector>

class List; 
/*klasa testujaca przechowujaca liste roznych kryteriow _filter */
class FilterCriteria{
  friend class List; //deklaracja przyjazni z klasa List w celu korzystania z jej skladowych prywatnych
  public:
//funkcja dodajaca funktor 
  void add(std::function<bool(int a)> licz);
//funkcja zwracajaca rozmiar
  int size() const;

//funkcja zwracajaca std::function do filtra i porownania
  std::function<bool(int)> get(int a);

  private:
    std::vector<std::function<bool(int a)>> _filter;
};
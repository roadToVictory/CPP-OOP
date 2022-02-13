#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>

/*klasa reprezentujaca zbior liczb*/
class List{
  public:
//klasa korzysta z wygenerowanego przez kompilator konstruktora domyslnego

  //funkcja wstawiajaca liczbe do zbioru
    void insert(int liczba);
  
  //funkcja wypisujaca zbior liczb
    void print(std::string napis="") const;

  //przeciazenie operatora []
    int& operator[](int ind);

  //funkcja separujaca liczby wg podanego warunku
    List filter(std::function<bool(int a)> licz);

  private:
    std::vector<int> _liczby;

};
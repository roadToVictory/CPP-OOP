#pragma once

#include <iostream>
#include <utility>

/* klasa reprezentujaca tablice liczb calkowitych*/
class MyArray{
  //przeciazenie operatora wypisania
  friend std::ostream& operator<<(std::ostream&str, const MyArray &n);
  
  public:
  //konstruktor domyslny
    MyArray() = default;
  //konstruktor z parametrem okreslajacym ilosc
    MyArray(int rozmiar);
  //desktruktor
    ~MyArray();
  //konstruktor kopiujacy
    MyArray(const MyArray &n);
  //konstruktor przenoszacy
    MyArray(MyArray &&n);
  //przecizaenie operatora =
    MyArray& operator=(const MyArray &n);

  //metoda zwracajaca rozmiar
    int size() const;
  //gettery
  int* getNext() {return _tablica;};

  //przeladowanie operatora []
    const int& operator [](const int ind) const;
    int& operator [](const int ind);

  //przeladowanie operatora ++
    MyArray operator++(const int x);

  //przeladowanie operatora --
    MyArray& operator--();

    //przeciazenie operatora +=
    MyArray& operator+=(const MyArray &n);

    //funkcja wypisuajca
    void print(const char *tekst) const;

  private:
    int *_tablica=nullptr;
    int _ilosc=0;
    MyArray* _next = nullptr;
};

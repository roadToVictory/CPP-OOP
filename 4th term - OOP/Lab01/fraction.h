#pragma once
#include <iostream>
#include <utility>

/*
Klasa opisujaca ulamki wraz z potrzebnymi metodami oraz przeciazeniami operatorow
*/
class Fraction{
  //zaprzyjazniona metoda przeciazajaca operator <<
  friend std::ostream& operator<<(std::ostream& str, const Fraction &frac);

  public:
    //konstruktor tworzacy nowy obiekt Fraction
    explicit Fraction(int licznik, int mianownik=1);
    //konstruktor kopiujacy
    Fraction(const Fraction &frac): _l(frac._l), _m(frac._m){};
    //konstruktor przenoszacy
    Fraction(Fraction &&frac): _l(std::exchange(frac._l,0)), _m(std::exchange(frac._m,1)){}
    //funkcja "skracajaca" ulamki
    void simplify();
    //funkcja zwracajaca ulamek dziesietny
    operator double() const;
    //przeciazenie operatora logicznego >
    bool operator>(const Fraction& frac) const;
    //przeciazenie operatora *
    Fraction operator*(const Fraction &frac) const{
      return Fraction(_l*frac._l, _m*frac._m);
    }
    //przeciazenie operatora *
    friend Fraction operator* (int mn, const Fraction &frac);
    //przeciazenie operatora +
    Fraction operator+ (const Fraction &frac) const;
    //przeciazenie operatora =
    Fraction& operator=(const Fraction &frac);
    //przeciazenie operatora +=
    Fraction &operator += (int a);
    //przeciazenie operatora []
    int operator[](const int a) const;
    //przeciazenie operatora liczby przeciwnej  -
    friend Fraction operator-(Fraction &frac);


  private:
    int _l;
    int _m;
};
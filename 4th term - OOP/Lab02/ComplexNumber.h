#pragma once
#include <iostream>

/* klasa reprezentująca liczbe zespolona */
class ComplexNumber{
  public:
  //konstruktor domyslny
    ComplexNumber(){_im=0; _re=0;};
  // konstruktor obiektu
    explicit ComplexNumber(double re, double im=0);
  //konstruktor kopiujacy
    ComplexNumber(const ComplexNumber& n);
  //konwersja do doublea
    explicit operator double() const{return (double)_re;}
  //przeciazenie operatora + 
    ComplexNumber operator+(const ComplexNumber &n) const;
  //przeciazenie operatora-
    ComplexNumber operator-(const ComplexNumber &n) const;
  //przeciazenie operatora =
    ComplexNumber& operator=(const ComplexNumber &n);
  //przeciazenie operatora *
    ComplexNumber operator*(const ComplexNumber &n) const;
  //przeciazenie operatora *=
    ComplexNumber &operator*=(int liczba);
  //przeciazenie operatorów post- i preinkrementacji
    ComplexNumber & operator++(); //preinkrementacja
    ComplexNumber operator ++(const int liczba); //post
  //przecizenie operatora []
    double& operator[](int n);
  //przeciazenie operatora >
    bool operator>(const ComplexNumber &n) const;
  

  // przeciazony operator << do wypisywania
  friend std::ostream& operator<<(std::ostream& str, const ComplexNumber &n);
  friend ComplexNumber operator+(double liczba ,const ComplexNumber &n);

  private:
    double _re;
    double _im;
};
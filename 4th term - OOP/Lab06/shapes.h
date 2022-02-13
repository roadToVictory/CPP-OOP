#pragma once
#include <iostream>
#include "wirtualne.h"


/**
  Klasa reprezentująca obiekt kazdego typu
*/
class Shape: public Drawable, public Transformable{
  public:
  //wirualny destruktor
    virtual ~Shape() = default;
};

/**
  Klasa reprezentująca figure zamknieta
*/
class ClosedShape: public Shape{
  public:
  //wirtualny destruktor
   virtual ~ClosedShape() = default;
  //funkcja do obliczania pola
    virtual double area() const =0;
};

/**
  Klasa reprezentująca punkt
  Dziedziczaca po Shape, poniewaz jest obiektem geometrycznym
*/
class Point: public Shape{
  public:
  //konstruktor tworzacy obiekt
    Point(double x, double y): m_x(x), m_y(y){}

  //przeciezenie operatora <<
    friend std::ostream& operator<<(std::ostream& str, const Point& point){
      str<<"("<<point.m_x<<", "<<point.m_y<<")";
      return str;
      //(1.5, 3)
    }
  //funkcja do rysowania
    void draw() override{};
  //funkcja przesuwajaca
    void shift(double x_sh, double y_sh) override;

  //gettery
    double getX() const {return m_x;}
    double getY() const {return m_y;}

  protected:
    double m_x;
    double m_y;
};


/**
  Klasa reprezentująca okrag
  Dziedziczaca po ClosedShape, poniewaz jest obiektem geometrycznym zamknietym
*/
class Circle: public ClosedShape{
  public:
  //konstruktor
    Circle(Point point, double r): m_srodek(point), m_r(r){}
  //funkcja do obliczania obwodu
    double length() override;
  
  //funkcja do obliczania pola
    double area() const override;

  //funkcja do przesuniecia
    void shift(double x_sh, double y_sh) override;

  //funkcja do rysowania
    void draw() override;

  protected:
    Point m_srodek;
    double m_r;
};

/**
  Klasa reprezentująca odcinek
  Dziedziczaca po Shape, poniewaz jest obiektem geometrycznym, ale nie zamknietym
*/
class Section: public Shape{
  public:
  //konstruktor
    Section(const Point pocz, const Point kon): m_poczatek(pocz), m_koniec(kon){}
  //konstruktor kopiujacy
    Section(const Section &sec): m_poczatek(sec.m_poczatek), m_koniec(sec.m_koniec){}

  //funkcja do obliczania obwodu
    double length() override;

  //funkcja do przesuniecia
    void shift(double x_sh, double y_sh) override;

  //funkcja do rysowania
    void draw() override;

  //gettert
   Point pocz() const {return m_poczatek;}
   Point kon() const{return m_koniec;}

  protected:
    Point m_poczatek;
    Point m_koniec;

};

/**
  Klasa reprezentująca Deltoid
  Dziedziczaca po ClosedShape, poniewaz jest obiektem geometrycznym zamknietym
*/
class Deltoid: public ClosedShape{
  public:
//konstruktor
   Deltoid(const Point a1, const Point a2, const Point a3, const Point a4): m_A1(a1), m_A2(a2), m_A3(a3), m_A4(a4){}

//konstruktor 
  Deltoid(const Section d1, const Section d2): m_A1(d1.pocz()), m_A2(d2.pocz()), m_A3(d1.kon()), m_A4(d2.kon()){}

  //funkcja do obliczania obwodu
    double length() override;
  
  //funkcja do obliczania pola
    double area() const override;

  //funkcja do przesuniecia
    void shift(double x_sh, double y_sh) override;

  //funkcja do rysowania
    void draw() override;


  protected:
    Point m_A1;
    Point m_A2;
    Point m_A3;
    Point m_A4;

};
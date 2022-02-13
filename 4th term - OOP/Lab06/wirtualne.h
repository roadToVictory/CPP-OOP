#pragma once

/**
  Klasa do rysowania ksztaltow
*/
class Drawable{
  public:
  //wirtualny destruktor
    virtual ~Drawable() = default;
  //funkcja do obliczania obwodu
    virtual double length(){return .0;}
  //funkcja do rysowania
    virtual void draw() =0;
};

/**
  Klasa do przesuwania
*/
class Transformable{
  public:
  //wirtualny destruktor
    ~Transformable() = default;
  //funkcja do obliczania pola
    virtual void shift(double x_sh, double y_sh) =0;
};




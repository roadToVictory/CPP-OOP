#include "shapes.h"
#include <cmath>

void Point::shift(double x_sh, double y_sh){
  m_x+=x_sh;
  m_y+=y_sh;
}
///////////////
double Circle::length(){
  return 2*M_PI*m_r;
}

double Circle::area() const{
  return M_PI*m_r*m_r;
}

void Circle::shift(double x_sh, double y_sh){
  m_srodek.shift(x_sh, y_sh);
}

void Circle::draw(){
  std::cout<< "Rysujemy kolo o srodku "<<m_srodek<<" i promieniu "<<m_r<<std::endl;
  //Rysujemy kolo o srodku (1.5, 3) i promieniu 3
}

/////////////
void Section::draw(){
  std::cout<< "Rysujemy odcinek od "<<m_poczatek<<" do "<<m_koniec<<std::endl;
}

double Section::length(){
  return sqrt( pow(m_koniec.getX()-m_poczatek.getX(),2) + pow(m_koniec.getY()-m_poczatek.getY(),2) );
}

void Section::shift(double x_sh, double y_sh){
  m_koniec.shift(x_sh, y_sh); //shift z klasy Point
  m_poczatek.shift(x_sh, y_sh);
}

//////

 double Deltoid::length(){
   return sqrt( pow( (m_A2.getX() - m_A1.getX()),2) + pow( (m_A2.getY() - m_A1.getY()),2)) + sqrt( pow( (m_A4.getX() - m_A1.getX()),2) + pow( (m_A4.getY() - m_A1.getY()),2)) + sqrt( pow( (m_A3.getX() - m_A2.getX()),2) + pow( (m_A3.getY() - m_A2.getY()),2)) + sqrt( pow( (m_A4.getX() - m_A3.getX()),2) + pow( (m_A4.getY() - m_A3.getY()),2));
 }
  
 
 double Deltoid::area() const{
      return Section(m_A1, m_A3).length() * Section(m_A2,m_A4).length();
}


  void Deltoid::shift(double x_sh, double y_sh){
      m_A1.shift(x_sh, y_sh);
      m_A2.shift(x_sh, y_sh);
      m_A3.shift(x_sh, y_sh);
      m_A4.shift(x_sh, y_sh);
  }

  void Deltoid::draw(){
      std::cout<< "Rysujemy Deltoid o wierzcholkach "<<m_A1<<", "<<m_A2<<", "<<m_A3<<", "<<m_A4<<std::endl;
  }

#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>

/**
  Klasa reprezentujaca wydatki
*/
class Expense{
  public:
  //konstruktor z argumentem typu std::string i std::vector
    Expense(const std::string dzien, const std::vector<double> kwoty): m_dzien(dzien), m_kwoty(kwoty){};
  //destruktor domyslny
    ~Expense() = default;

  //funkcja do wypisywania
    void print() const;

  //funkcja obliczajaca srednie wydatki
    double mean() const;

  //przecizazenie operatora [] do porownywnaia
    double operator[](unsigned k) const;

  private:
    std::string m_dzien;  // dzien tygodnia
    std::vector<double> m_kwoty;  // wydana kwota

};
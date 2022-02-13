#pragma once
#include "Expense.h"
#include <functional>
/**
  Klasa reprezentujaca wydatki
*/
class Table{
  public:
  //konstruktor domyslny
    Table() = default;
  
  //destrktur domyslny
    ~Table() = default;

  //przeciazenie operatora +=
    void operator+=(const Expense &ex);

  //funkcja do wypisywania
    void print() const;

  //funkcja do sortowania po wybranej kolumnie, modyfikuje wejściowy obiekt
    Table& sort(unsigned k);

  //funkcja do sortowania po sredniej
    Table &sortByMean();

  private:
    std::vector<Expense> m_tab; //tablica przechowujaca wydatki
};
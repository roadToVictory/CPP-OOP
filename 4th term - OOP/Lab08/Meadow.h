#pragma once
#include "Animals.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
#include <map>

/**
Klasa opisujaca pastwisko
*/
class Meadow{
  public:
  //konstruktor domyslny
    Meadow() = default;
  //destruktor domyslny
    ~Meadow() = default;

  //funkcja "dodajaca" zwierze na lake
    void add(std::unique_ptr<Animal> zwierze);  
  //funkcja wypisujaca
    void print(const std::string text) const; 
  //funkcja zliczajaca wystapienia imienia
    void countNames() const;
  //funkcja "pobierajaca" owce do strzyzenia
    std::vector<Sheep*> getSheepHerd();
      //std::vector<Sheep*> herd = meadow.getSheepHerd();

  private:
    std::vector< std::unique_ptr<Animal> > m_laka;
};
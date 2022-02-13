#pragma once
#include <iostream>


namespace num{
/**
@fn srednia
@brief szablon funkcji do obliczania sredniej
@param tab tablica z liczbami
@param rozmiar liczba elementow w tablicy
@return srednia liczb podanych w tab
*/
template<typename T>
   double srednia(const T *tab, const int rozmiar){
    double suma=0;
    for(int i=0; i<rozmiar; i++)
      suma+=tab[i];


    return suma/rozmiar;
  }

/**
@fn srednia
@brief szablon funkcji do obliczania sredniej
@param tab tablica z liczbami
@return srednia liczb podanych w tab
*/
template<typename T, const int size>
   double srednia(const T (&tab)[size]){
    return srednia(tab, size);
  }


/**
@fn czyWszystkiePierwsze
@brief szablon funkcji sprawdzajacej czy wszystkie liczby w tablicy z podanego zakresu sa liczbami pierwszymi
@param tab tablica z liczbami
@return true lub false w zaleznosci od wyniku sprawdzenia
@warning jesli zakres jest nieprawidlowy lub wykracza poza rozmiar tabeli zwraca odpowiedni komunikat oraz false
*/
template<int start, int stop, const int size,typename T>
bool czyWszystkiePierwsze(const T (&tab)[size]){
  if(start<stop && stop<=size){
    for(int i=start; i<stop; i++){
      for(int j=2; j<abs(tab[i]/2); j++)
        if(!(tab[i]%j))
          return false;
    }
    return true;
  }
  else {std::cout<<"Nieprawidlowy zakres!"<<std::endl;
  return false;}
}


/**
@fn text
@brief funkcja zwracajaca napis TRUE lub FALSE w zaleznosci od wartosci przyjmowanego argumentu
@param pierwsza wartosc logiczna
@return napis TRUE/FALSE
*/
inline const char* text(const bool pierwsza){
  return pierwsza? "TRUE" : "FALSE";
}

}
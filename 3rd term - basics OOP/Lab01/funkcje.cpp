#include<iostream>
#include "funkcje.h"

using namespace std;


int silnia(int liczba){
  int silnia=1;
  if(liczba==0)
    return 1;
  else if (liczba<0){
    cout<<"brak rozwiazania ";
    return -1;
  }
  else
    for(int i=liczba; i>1; i--)
      silnia*=i;

  return silnia;
}

int silnia_rec(int liczba){
  if(liczba==0)
    return 1;

  else if (liczba<0){
    cout<<"brak rozwiazania ";
    return -1;
  }
  else
    return liczba*silnia_rec(liczba-1);
}

void wypisz(double tab[],int size){
  for(int i=0; i<size; i++)
    cout<<tab[i]<<" ";
  cout<<endl;
}

void powiel(double tab[], double mnoznik, int size){
  for(int i=0; i<size; i++)
    tab[i]*=mnoznik;
}

double suma(double tab[], int size){
  double sum = 0;

  for(int i=0; i<size; i++)
    sum+=tab[i];

  return sum;
}

double srednia(double tab[], int size){
  int sum1 = suma(tab, size);
  return sum1/size;
}
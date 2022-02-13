#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

/**
*Szablon klasy tablicy asocjacyjnej
*/
template <typename T, typename R>
class Assoc{
  public:
    //konstruktor domyslny
      Assoc() = default;
    
    //funcja dodajaca element do tablicy
      void insert(T k, R v);
    
    //funkcja wypisujaca
      void print(std::string text) const;
    
    //przeciazenie operatora[]
      R& operator[](const T& as);
      const R& operator[](const T& as) const;

    //funkcja sprawdzajaca istnienie
      bool contains(const T& text) const;

  private:
    std::vector<T> _key;
    std::vector<R> _value;
};

///////////////////////////////////////
template <typename T, typename R> 
void Assoc<T,R>::insert(T k, R v){
  _key.push_back(k);
  _value.push_back(v);
}

///////////////////////////////////////
template <typename T, typename R> 
void Assoc<T,R>::print(std::string text) const{
  for(unsigned i=0; i<_key.size();i++){
    std::cout<<"--- "<<text<<" --- klucz: "<<_key[i]<<" wartosc: "<<_value[i]<<std::endl;
  }
}

std::string xxx(std::string x){return "";}
template <typename T>T xxx(T x){return 0;}
////////////////////////////////////////
template <typename T, typename R> 
R& Assoc<T,R>::operator[](const T& as){

  for(unsigned i=0; i<_key.size();i++)
    if(as==_key[i])
      return _value[i];
  _key.push_back(as);
  _value.push_back(xxx (R()));
  return _value[_value.size()-1];
}


template <typename T, typename R> 
const R& Assoc<T,R>::operator[](const T& as) const{
  auto result = std::find(begin(_key), end(_key), as);

  if(result!=std::end(_key)){
    return _value[_value.size()>0?_value.size()-1:0];
  }
  else{
    return _value[_value.size()]; //nie istniejace
  }
}

//////////////////////////////////////////
template <typename T, typename R> 
bool Assoc<T,R>::contains(const T& text) const{
  auto result = std::find(begin(_key), end(_key), text);

  if(result!=std::end(_key))
    return true;
  else return false;
}

/////////////////////////////////////////
std::string print(bool exist){
  return exist? "Znaleziono": "Nie znaleziono";
}

////////////////////////////////////////
std::string operator*(const std::string text, const int x){
  std::string result="";
  for(int i=0; i<x;i++)
    result+=text;
  return result;
}

std::string operator*(const int x, const std::string text){
  std::string result="";
  for(int i=0; i<x;i++)
    result+=text;
  return result;
}


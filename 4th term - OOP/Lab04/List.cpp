#include "List.h"

void List::insert(int liczba){
  _liczby.push_back(liczba);
}

void List::print(std::string napis) const{
  std::cout<<napis<<"[";
  for(unsigned i=0; i<_liczby.size(); i++){
    std::cout<<_liczby[i]<<" ";
  }
  std::cout<<"]"<<std::endl;
}

int& List::operator[](int ind){
  return _liczby[ind];
}

List List::filter(std::function<bool(int a)> licz){
  List temp;  //korzysta z konstrutora domyslnego bezargumentowego

  for(unsigned i=0; i<_liczby.size(); i++){
    if(licz(_liczby[i])==true)
      temp._liczby.push_back(_liczby[i]); // do nowo powstalnego obiektu dolacza na koniec elementy spelniajace warunek z licz
  }

  return temp;
}

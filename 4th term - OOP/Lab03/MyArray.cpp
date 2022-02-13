#include "MyArray.h"

MyArray::MyArray(int rozmiar):_ilosc(rozmiar){
  _tablica = new int[_ilosc];
  for(int i=0; i<_ilosc;i++)
    _tablica[i]=0;
  _next = nullptr;
}

MyArray::~MyArray(){
  if(_tablica){
    delete[] _tablica;
    _tablica = nullptr;
    _next = nullptr;
    _ilosc =0;
  }
}

MyArray::MyArray(const MyArray &n){
  if(this==&n) 
    return;

  _tablica = new int[n._ilosc];
  _ilosc = n._ilosc;
  for(int i=0; i<_ilosc;i++)
    _tablica[i] = n._tablica[i];
}

MyArray::MyArray(MyArray &&n): 
  _tablica(std::exchange(n._tablica, nullptr)),
  _ilosc(std::exchange(n._ilosc,0)),
  _next(std::exchange(n._next,nullptr))
  {}

std::ostream& operator<<(std::ostream&str, const MyArray &n){
  if(n._ilosc>0){
    std::cout<<"[";
    for(int i=0; i<n._ilosc;i++){
      std::cout<<n._tablica[i]<<", ";
    }
    std::cout<<"]";
  }
  return str;
}

int MyArray::size() const{
  if(_next == nullptr)
    return _ilosc;
  else return _ilosc + _next->size();
}

const int& MyArray::operator [](int ind) const{
  return _tablica[ind];
}

int& MyArray::operator [](int ind) {
  return _tablica[ind];
}

MyArray& MyArray::operator=(const MyArray &n){
  if(this==&n) 
    return *this;

  delete []_tablica;
  _tablica = new int[n._ilosc];
  _next = n._next;
  _ilosc = n._ilosc;

  for(int i=0;i<_ilosc; i++)
    _tablica[i] = n._tablica[i];

  return *this;
}

 MyArray MyArray::operator++(const int x){
   MyArray temp = *this;
   for(int i=0; i<_ilosc; i++)
    _tablica[i] +=1;
  
  return temp;
 }

 MyArray& MyArray::operator--(){
   
   for(int i=0;i<_ilosc;i++)
    _tablica[i] -=1;
  return *this;
 }

 MyArray& MyArray::operator+=(const MyArray &n){
  // if(_next==nullptr)
   // _next = 
  return *this;
 }

 void MyArray::print(const char *tekst) const{
   std::cout<<tekst<<"=[";
   for(int i=0; i<_ilosc;i++)
    std::cout<<_tablica[i]<<", ";
  std::cout<<"]";
 }
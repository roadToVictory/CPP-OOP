#include "myString.h"

namespace mystring{

String::String(const char *znaki){
    _dlugosc = strlen(znaki);
    _tekst = new char[_dlugosc+1];
   
    for(unsigned i=0; i<_dlugosc; i++)
        _tekst[i] = znaki[i];
    _tekst[_dlugosc] = '\0';

}
    
String::String(const String &str) :_dlugosc(str._dlugosc){
    _tekst = new char[_dlugosc+1];
    for(unsigned i=0; i<_dlugosc; i++)
        _tekst[i] = str._tekst[i];
    _tekst[_dlugosc] = '\0';
}

String::String(String &&str): _dlugosc(std::move(str._dlugosc)), _tekst(std::move(str._tekst)){
   str._tekst = nullptr;
}

String::~String(){
  if(_tekst)
    delete []_tekst;
  _dlugosc = 0;
}

void String::print(const char *znaki) const{
    std::cout<<znaki<<_tekst<<std::endl;
}

bool String::operator ==(const char* znaki) const{
    unsigned dl_zn = strlen(znaki);
    if(_dlugosc != dl_zn)
        return false;
    int i=0;
    while(_tekst[i]!='\0'){
        if(_tekst[i]!=znaki[i])
            return false;
        i++;
    }
    return true;
}

bool String::operator ==(const String &str) const{
    if(_dlugosc != str._dlugosc)
        return false;
    
    int i=0;
    while(_tekst[i]!='\0'){
        if(_tekst[i]==str._tekst[i])
            i++;
        else return false;
    }
    return true;
}

String::operator char*() const{
    return _tekst;
}

String& String::operator =(const String &str){
    if(this == &str)
     return *this;

  delete []_tekst;
  _dlugosc = str._dlugosc;
  _tekst = new char[_dlugosc+1];

  for(unsigned i=0; i<_dlugosc; i++)
    _tekst[i] = str._tekst[i];
  
  _tekst[_dlugosc] = '\0';
  return *this;
}

String& String::operator =(const char *str){
    delete []_tekst;
    _dlugosc = strlen(str);
    _tekst = new char[_dlugosc+1];

  for(unsigned i=0; i<_dlugosc; i++)
    _tekst[i] = str[i];
  
  _tekst[_dlugosc] = '\0';
  return *this;
}

/*String String::operator +(const char *znaki) const{
    String temp("");
    temp._dlugosc = _dlugosc + strlen(znaki);
    temp._tekst = new char[temp._dlugosc+1];

    for(unsigned i=0; i<_dlugosc;i++)
        temp._tekst[i] = _tekst[i];
    
    for(unsigned i=_dlugosc, j=0; j<strlen(znaki);i++,j++)
        temp._tekst[i] = znaki[j];
    temp._tekst[temp._dlugosc]='\0';
    return temp;
}*/

String String::operator +(const char znak) const{
    String temp("");
    delete [] temp._tekst;  //!!! bez tego sa wycieki
    temp._dlugosc = _dlugosc +1;
    temp._tekst = new char[temp._dlugosc+1];
    for(unsigned i=0; i<temp._dlugosc;i++)
        temp._tekst[i] = _tekst[i];
    temp._tekst[temp._dlugosc-1] = znak;
    temp._tekst[temp._dlugosc] = '\0';
    return temp; 
}

String String::operator +(const String &str) const{
    String temp;
    temp._dlugosc = _dlugosc + str._dlugosc;
    temp._tekst = new char[temp._dlugosc+1];
    for(unsigned i=0; i<_dlugosc;i++)
        temp._tekst[i] = _tekst[i];
    
    for(unsigned i=_dlugosc, j=0; j<str._dlugosc;i++,j++)
        temp._tekst[i] = str._tekst[j];
    temp._tekst[temp._dlugosc]='\0';

    return temp; 
}

String operator*(unsigned ilosc, const String &str){
    if(ilosc<=0)
        return String("");
    
    char *wynik = new char[strlen(str)*ilosc +1];
    char result[50];

    for(unsigned i=0; i<ilosc;i++)
      for(unsigned j=0; j<strlen(str); j++)
          //wynik[i*strlen(str)+j] = str[j];
        strcpy(wynik+i*strlen(str), str);
    
    wynik[strlen(str)*ilosc]='\0';
    strcpy(result, wynik);
    //return String(wynik);
    delete []wynik;
    return result;

}


} //namespace
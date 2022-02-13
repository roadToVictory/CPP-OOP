#include "fraction.h"

int nwd(int m, int n){
	int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
} 

void Fraction::simplify(){
  int najw = nwd(_l, _m);
  _l = _l/najw;
  _m = _m/najw;
}

Fraction::Fraction(int licznik, int mianownik){
  _l = licznik;
  _m = mianownik;
  simplify();
}

Fraction::operator double() const{
  return (double)_l/(double)_m;
}

std::ostream& operator<<(std::ostream& str, const Fraction &frac){
  if(frac._m ==1)
    return str<<frac._l;
  else return str<<frac._l<<"/"<<frac._m;
}

bool Fraction::operator>(const Fraction& frac) const{
  if(_l==frac._l){
    if(_m<frac._m)
      return true;
    else return false;
  }
  return _l>frac._l;
}

Fraction operator* (int mn, const Fraction &frac){
  return Fraction(mn*frac._l,frac._m);
}

Fraction Fraction::operator+ (const Fraction &frac) const{

 int l = _l*frac._m + frac._l*_m;
 int m = _m*frac._m;
 return Fraction(l,m);
}

Fraction& Fraction::operator=(const Fraction &frac){
  //_l=0; _m=0;
  if(*this!=frac){
  _l = frac._l;
  _m = frac._m;
  }
  return *this;
}

Fraction& Fraction::operator += (int a){
  _l+=a*_m;
  return *this;
}

int Fraction::operator[](const int a) const{
  return a==0? _l : _m;
}

Fraction operator-(Fraction &frac){
  return Fraction(-frac._l, frac._m);
}
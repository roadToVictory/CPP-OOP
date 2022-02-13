#include "Animals.h"

Sheep::~Sheep(){
  print();
  std::cout<<" wraca do zagrody"<<std::endl;
}

void Sheep::print() const{
  std::cout<<"- Owca "<<m_nazwa;
  (m_ostrzyzona)?std::cout<<" ostrzyzona" : std::cout<<" nieostrzyzona";
}

void Cow::print() const{
  std::cout<<"- Krowa " <<m_nazwa;
}

Cow::~Cow(){
  print();
  std::cout<<" wraca do zagrody"<<std::endl;
}

void Horse::print() const{
  std::cout<<"- Kon " <<m_nazwa;
}

Horse::~Horse(){
  print();
  std::cout<<" wraca do zagrody"<<std::endl;
}

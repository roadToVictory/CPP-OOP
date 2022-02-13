#include "Meadow.h"

void Meadow::add(std::unique_ptr<Animal> zwierze){
  m_laka.push_back(std::move(zwierze));
}  



void Meadow::print(const std::string text) const{
  std::cout<< "=== "<<text<<" === "<<std::endl;
  for(auto& x: m_laka){
    x->print();
    std::cout<<std::endl;
  }
}

 void Meadow::countNames() const{
   std::map<std::string, int> ile;

   for(auto& x: m_laka)
    ile[x->name()]++;

   for(auto& x: ile)
     std::cout<<x.first<<": "<<x.second<<std::endl;
 }

 std::vector<Sheep*> Meadow::getSheepHerd(){
    std::vector<Sheep*> tmp;
    
    // for(const auto& animal: m_laka){
    //   try{
    //   if(typeid(dynamic_cast<Sheep&>(*animal))==typeid(Sheep))
    //     tmp.push_back(dynamic_cast<Sheep*>(animal.get()));
    //   }catch(const std::bad_cast& e){}
    // }

    for(const auto& animal: m_laka){
      Sheep* sheep = dynamic_cast<Sheep*>(animal.get());
      if(sheep) tmp.push_back(sheep);
    }
    return tmp;
 }
#include "FilterCriteria.h"
#include "List.h"

void FilterCriteria::add(std::function<bool(int a)> licz){
  _filter.push_back(licz);
}

int FilterCriteria::size() const{
  return _filter.size();
}


 std::function<bool(int)> FilterCriteria::get(int a){
   return _filter[a];
 }
#include "Table.h"

void Table::operator+=(const Expense &ex){
  m_tab.push_back(ex);
}

/*auto f = [](const Expense &ex){
  return ex.print();
};*/

void Table::print() const{
  std::for_each(m_tab.begin(), m_tab.end(), [](const Expense &ex){ return ex.print();});
  std::cout<<std::endl;
}

bool compare(const Expense &ex1, const Expense &ex2, unsigned k){
  return ex1[k]<ex2[k];
}

Table& Table::sort(unsigned k){
  if(m_tab.size() < k+1){ // k+1 bo indeksy od 0
    std::cout<<"Indeks "<<k<<" nieprawidlowy!"<<std::endl;
    return *this;
  }
  using namespace std::placeholders;
  std::sort(m_tab.begin(), m_tab.end(), std::bind(compare, _1, _2, k));
  return *this;
}

/*auto cmp=[](const Expense &ex1, const Expense &ex2){
  return ex1.mean()<ex2.mean();
};*/

Table& Table::sortByMean(){
  std::sort(m_tab.begin(), m_tab.end(), [](const Expense &ex1, const Expense &ex2){ return ex1.mean()<ex2.mean();});
  return *this;
}
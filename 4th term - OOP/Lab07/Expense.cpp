#include "Expense.h"

/*auto f = [](double x){
  std::cout<<std::setw(5)<<x;
};
*/

void Expense::print() const{
  std::cout<<m_dzien<<": ";
  std::for_each(m_kwoty.begin(), m_kwoty.end(), [](double x){
  std::cout<<std::setw(5)<<x; });
  std::cout<<std::endl;

}

double Expense::mean() const{
  double suma = std::accumulate(m_kwoty.begin(), m_kwoty.end(), 0.0);
  return suma/m_kwoty.size();
}

double Expense::operator[](unsigned k) const{
  return m_kwoty[k];
}
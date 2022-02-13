#include <iostream>
#include <utility>

class Pasture{
    friend std::ostream& operator <<(std::ostream &strumien, const Pasture &pas);
    public:
        Pasture(): _pow(0),_ilosc(0), _pas(0) {};   
        Pasture(double a, int ilosc);
        Pasture(const Pasture &pas);
        Pasture(Pasture &&pas);
        ~Pasture();
        Pasture& operator =(const Pasture &pas);
        Pasture operator +(const Pasture &pas) const;
        Pasture& operator *=(const double a);
        bool operator()(const Pasture &pas, const Pasture &pas1) const;


    private:
        double _pow;
        int _ilosc;
        bool *_pas;
};

Pasture operator*(const double a, const Pasture &pas);
Pasture operator*(const Pasture &pas, const double a);
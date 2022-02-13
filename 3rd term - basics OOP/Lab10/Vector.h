#include <iostream>
#include <cstring>
#include <cmath>
#include <utility>

class Vector{
    public:
        explicit Vector(int size=0);
        ~Vector();
        Vector(const Vector &vec);
        Vector(Vector &&vec);
        double &at(int wartosc);
        void print(const std::string text) const;
        static double dot(const Vector &vec1, const Vector &vec2);
        double norm() const;
        operator double() const;
        static Vector sum(const Vector &vec1, const Vector &vec2);
        static Vector sum(const Vector &vec1, double n);

    private:
        int _rozmiar;
        double *_wektor;
};
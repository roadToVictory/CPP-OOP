#include <iostream>
#include <cstring>
#include <cmath>
#include <math.h>
#include <utility>

class Vector2D{
    public:
        static int count;
        Vector2D(std::string nazwa="Vx") : _nazwa(nazwa), _x(0.0), _y(0.0){count++;}
        ~Vector2D(){count--;}
        Vector2D(const Vector2D &vector); //kopiujacy
        Vector2D(Vector2D &&vector);        //przenoszacy

        static Vector2D fromCarthesian(std::string name, double x, double y);
        static Vector2D fromCarthesian(double x, double y);
        static Vector2D fromPolar (std::string name, double r, double phi);
        void print(const std::string nazwa) const;
        double dot(const Vector2D &vector) const;
        Vector2D add(const Vector2D &vector) const;

    private:
        std::string _nazwa;
        double _x;
        double _y;
};
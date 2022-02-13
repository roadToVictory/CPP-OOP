#ifndef MAPPOINT_h
#define MAPPOINT_h

#include <iostream>
#include <cstring>
#include <math.h>

#include "MapDist.h"
class MapDist;

class MapPoint{
    friend class MapDist;
    friend const MapDist distance(const MapPoint &city1, const MapPoint &city2);
    friend MapPoint inTheMiddle(const MapPoint *city1, const MapPoint *city2, std::string nazwa);
    public:
        MapPoint(std::string nazwa, float longitude, float latitude);
        MapPoint(std::string nazwa, float longitude, char EW, float latitude, char NS);
        ~MapPoint();

        void print()const;
        void movePoint(const double longitudeShift, const double latitudeShift);
        const MapPoint& closestFrom(const MapPoint *city1, const MapPoint *city2) const;
        std::string getName() const;

    private:
        std::string _nazwa;
        float _longitude;
        float _latitude;
        char _polkulaNS;     //szerokosc
        char _polkulaEW;     //dlugosc
};
#endif
#ifndef MAPDIST_H
#define MAPDIST_H
#include <iostream>

#include "MapPoint.h"
class MapPoint;

class MapDist{
    friend class MapPoint;
    friend const MapDist distance(const MapPoint &city1, const MapPoint &city2);
    public:
        MapDist() : _lati(0), _longi(0){};
        MapDist(const MapPoint &city1,const MapPoint &city2);
        float angularDistance() const;


        float getlongitude() const {
            return _longi;
        }

        float getlatitude() const {
            return _lati;
        }
        

    private:
        float _lati;
        float _longi;
};
#endif
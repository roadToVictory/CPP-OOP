#include "MapDist.h"

MapDist::MapDist(const MapPoint &city1,const MapPoint &city2){
    _lati = fabs(city1._latitude - city2._latitude);
    _longi = fabs(city1._longitude - city2._longitude);
}

const MapDist distance(const MapPoint &city1,const MapPoint &city2){
    return MapDist(city1, city2);
}

float MapDist::angularDistance() const{
    return sqrt(_lati*_lati + _longi*_longi);
}
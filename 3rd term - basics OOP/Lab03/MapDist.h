#ifndef MAPDIST_H
#define MAPDIST_H



//#pragma once
#include "MapPoint.h"

struct MapDist{
    float longitude;
    float latitude;
};

MapDist distance(MapPoint city1, MapPoint city2);
float angularDistance(const MapDist d);
MapPoint closestFrom(MapPoint *city1, MapPoint *city2, MapPoint *city3);
#endif
//#pragma once  

#ifndef MAPPOINT_H      //lub pragma once
#define MAPPOINT_H

#include <iostream>
#include <cmath>

struct MapPoint{
    std::string name;
    float longitude;
    float latitude;
    char polkulaNS;
    char polkulaEW;
};

MapPoint *construct(std::string nazwa, float longi, float lati);
MapPoint *construct(std::string nazwa, float longi, char EW, float lati, char NS);
void print(const MapPoint *city);
void movePoint(MapPoint *city, float longi, float lati);
MapPoint inTheMiddle(MapPoint *city1, MapPoint *city2, std::string nazwa);
void clear(MapPoint *city1, MapPoint *city2=nullptr, MapPoint *city3=nullptr);
//void clear(MapPoint *city1);

#endif
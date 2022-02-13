#include "MapPoint.h"


MapPoint::MapPoint(std::string nazwa, float longitude, float latitude){
    this->_nazwa = nazwa;  
    _longitude = longitude;
    _latitude = latitude;

    if(_longitude<0)
        _polkulaEW = 'W';
    else _polkulaEW = 'E';

    if(_latitude<0)
        _polkulaNS = 'S';
    else _polkulaNS = 'N';
}

MapPoint::MapPoint(std::string nazwa, float longitude, char EW, float latitude, char NS){
    _nazwa = nazwa;
    _polkulaNS = NS;
    _polkulaEW = EW;

    if(_polkulaNS == 'N')
        _latitude = latitude;
    else _latitude = latitude*(-1);

    if(_polkulaEW == 'E')
        _longitude = longitude;
    else _longitude = longitude*(-1);
}

MapPoint::~MapPoint(){
    std::cout<<"Usuwanie " << _nazwa<<std::endl;
    _nazwa = '\0';      // !
    _polkulaEW ='\0';
    _polkulaNS ='\0';
    _longitude =0;
    _latitude =0;
}

void MapPoint::print() const{
    std::cout<<"Wspolrzedne dla " << _nazwa << ": "<< fabs(_longitude)<<_polkulaEW<<", "<<fabs(_latitude)<<_polkulaNS<<std::endl;
}

void MapPoint::movePoint(const double longitudeShift, const double latitudeShift){
    _longitude +=longitudeShift;
    if(_longitude<0)
        _polkulaEW = 'W';
    else _polkulaEW = 'E';

    _latitude +=latitudeShift;
    if(_latitude<0)
        _polkulaNS = 'S';
    else _polkulaNS = 'N';
}

const MapPoint& MapPoint::closestFrom(const MapPoint *city1, const MapPoint *city2) const{
    MapDist d1 = distance(*this, *city1);
    MapDist d2 = distance(*this, *city2);
    
    if(d1.angularDistance() < d2.angularDistance())
        return *city1;
    else return *city2;
}

std::string MapPoint::getName() const{
    return _nazwa;
}

MapPoint inTheMiddle(const MapPoint *city1, const MapPoint *city2, std::string nazwa){
    return MapPoint(nazwa, (city1->_longitude+city2->_longitude)/2, (city1->_latitude + city2->_latitude)/2);
}
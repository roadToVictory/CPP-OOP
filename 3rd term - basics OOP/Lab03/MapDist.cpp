#include "MapDist.h"

MapDist distance(MapPoint city1, MapPoint city2){
    MapDist temp;
    temp.longitude = (city1.longitude - city2.longitude)*(-1);
    temp.latitude = city1.latitude - city2.latitude;
    return temp;
}

float angularDistance(const MapDist d){
    return sqrt(d.latitude*d.latitude + d.longitude*d.longitude);
}

MapPoint closestFrom(MapPoint *city1, MapPoint *city2, MapPoint *city3){
    float distance1 = angularDistance(distance(*city1, *city2));
    float distance2 = angularDistance(distance(*city1, *city3));

    return (distance1<distance2 ? *city2 : *city3);
   // return (angularDistance(distance(*city1, *city2))<angularDistance(distance(*city1, *city3)) ? *city2 : *city3);
}
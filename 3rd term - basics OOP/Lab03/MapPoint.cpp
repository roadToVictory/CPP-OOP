#include "MapPoint.h"

MapPoint *construct(std::string nazwa, float longi, float lati){
    MapPoint *temp = new MapPoint;
    (*temp).name = nazwa;
    temp->latitude = lati;
    temp->longitude = longi;
    if(temp->latitude < 0)
        temp->polkulaNS = 'S';
    else temp->polkulaNS = 'N';

    if(temp->longitude<0)
        temp->polkulaEW = 'W';
    else temp->polkulaEW = 'E';

    return temp;
}

MapPoint *construct(std::string nazwa, float longi, char EW, float lati, char NS){
    MapPoint *temp = new MapPoint;
    temp->name = nazwa;
    temp->polkulaNS = NS;
    temp->polkulaEW = EW;

    if(EW == 'E')
        temp->longitude = longi;
    else temp->longitude = longi * (-1);

    if(NS == 'N')
        temp->latitude = lati;
    else temp->latitude = lati * (-1);   

    return temp;
}

void print(const MapPoint *city){
    std::cout<<"Wspolrzedne dla " << city->name << ": " << 
        ((city->polkulaEW == 'E') ? city->longitude : fabs(city->longitude)) << city->polkulaEW <<", " <<
        ((city->polkulaNS == 'N') ? city->latitude : fabs(city->latitude)) << city->polkulaNS << std::endl;
}

void movePoint(MapPoint *city, float longi, float lati){
    city->latitude +=  lati;
    city->longitude += longi;

    if(city->latitude < 0)
        city->polkulaNS = 'S';
    else city->polkulaNS = 'N';

    if(city->longitude <0)
        city->polkulaEW = 'W';
    else city->polkulaEW = 'E';
}

MapPoint inTheMiddle(MapPoint *city1, MapPoint *city2, std::string nazwa){
    float longi = (city1->longitude + city2->longitude)/2;
    float lati = (city1->latitude + city2->latitude)/2;
    MapPoint *temp = construct(nazwa, longi, lati);
    MapPoint temp2;
    temp2.name = temp->name;
    temp2.latitude = temp->latitude;
    temp2.longitude = temp->longitude;
    temp2.polkulaEW = temp->polkulaEW;
    temp2.polkulaNS = temp->polkulaNS;
    delete temp;
    return temp2;
    //return *construct(nazwa, longi, lati);
}

void clear(MapPoint *city1, MapPoint *city2, MapPoint *city3){
    std::cout<<"Usuwanie " << city1->name << std::endl;
    delete city1;

    if(city2 && city3){
      std::cout<<"Usuwanie " << city2->name << std::endl;
      delete city2;

      std::cout<<"Usuwanie " << city3->name << std::endl;
      delete city3;
    }
}

/*  //if previous without default arguments
void clear(MapPoint *city1){
    std::cout<<"Usuwanie " << city1->name<<std::endl;
    delete city1;
}
*/

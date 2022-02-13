#pragma once
#include <iostream>
#include "shapes.h"
/*
  Zastosowana hierarchia klas:
    Klasy Drawable i Transformable to klasy wirtualne po ktorych dziedzicza ksztalty

    Klasa Shape reprezentuje obiekt kazdego typu

    Klasa ClosedShape dziedziczy po Shape bo jest ksztaltem ale wyszczegolnia ksztalty na ksztalty zamkniete

    Po Klasie Shape dziedzica Point i Section bo sa to obiekty geometryczne ale nie sa zamkniete wiec nie dziedzicza po ClosedShape

    Klasy Circle i Deltoid dziedzicza po Closed Shape bo sa zamkniete

*/

void draw(Drawable *drawa){
  drawa->draw(); //wywoluje draw odpowiedniego typu
}
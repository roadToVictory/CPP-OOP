/*  
  Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku. Zadanie opiera się na kodzie lab5 i polega na przekształceniu struktury listy jednokierunkowej w klasę.

  Klasa Element reprezentuje element listy jednokierunkowej i posiada prywatne pole typu char* oraz wskaźnik na następny element.
  Ponadto posiada kostruktory i destruktory oraz metody potrzebne, aby dostać się do prywatnych danych.
  
  Klasa StudList i zawiera prywatne pola: 
   wskaźniki na head i tail typu klasy Element oraz publiczne metody:
  * konstruktory ustawiający wskaźniki na NULL i ew. nadające nazwę (dawne initList),
  * destruktor usuwający wszystkie elementy listy oraz samą listę (dawne delList),
  * print - drukuje listę w postaci [w1, w2, w3],
  * clearList - usuwa wszystkie elementy z listy, włącznie ze zwolnieniem pamięci, ale nie usuwa samej listy,
  * append - wstawia wartość char*  lub Element na koniec listy,
  * removeFirst - usuwa pierwszy element z listy wraz z dealokacją pamięci obiektu typu Element,
  * getFirst - pobiera pierwszy element, usuwając go z listy, ale nie zwalniając pamięci.

  Należy zaprzyjażnić klasy, aby StudList mogła korzystać z priwatnych składowych klasy Element.

  Należy zadbać o zwolnienie pamięci przy usuwaniu elementów i czyszczeniu listy. Valgrind (make check) nie powinien wykazywać żadnych wycieków pamięci (leap) ani błędów (errors).

  Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
  Proszę pamietać o dokumentacji kodu.
*/

#include "studList.h"
#include <iostream>

using namespace std;

int main() {
    std::cout << "*** Lista 1 ***" << std::endl;
    StudList list1("Lista1");

    Element* agnieszka = new Element ("Agnieszka");
    list1.append(agnieszka);
    list1.append("Beata");
    list1.append("Maria");

    StudList* ptr1 = &list1;
    std::cout << "Pierwszy: " << ptr1->getHead()-> getName() << std::endl;
    std::cout << "Ostatni: ";
    ptr1->getTail()->printName();
    std::cout << std::endl;

    const StudList *ptrc=ptr1;
    std::cout << "Czy " << ptrc->getName() << " jest pusta? " 
              << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
    ptrc->print();

    std::cout << "\n*** Lista 2 ***" << std::endl;
    StudList list2("Lista2");
    
    Element adam ("Adam");
    list2.append(&adam);
    list2.append("Krzysztof");
    list2.append("Tomasz");
   
    list2.print();

    std::cout << "\n*** Usuwanie ***" << std::endl;
    StudList* ptr2 = &list2;
    Element* PtrAdam = ptr2->getFirst();

    ptr2->print();
    std::cout << "--- Usuwam wszystkie elementy hurtem" << std::endl;
    list1.clearList();
    std::cout << "Czy " << list1.getName() << " jest pusta? " 
              << (list1.isEmpty()?"tak":"nie") << std::endl;
    std::cout << "--- Nazwa nadal istnieje, ale lista jest pusta" << std::endl;     
    list1.print();
    list1.append(PtrAdam);
    ptr1->print();
    ptr1->getFirst();
    list1.clearList(); //próba usunięcia pustej listy
    
    std::cout << "--- Usuwam listę element po elemencie" << std::endl;   
    list2.print();
    list2.removeFirst();
    list2.print();
    list2.removeFirst();
    list2.print();
    list2.removeFirst();
    return 0;
}

/* Oczekiwany wynik: ./main
*** Lista 1 ***
Pierwszy: Agnieszka
Ostatni: Maria
Czy Lista1 jest pusta? Nie
Lista1 = [Agnieszka Beata Maria]

*** Lista 2 ***
Lista2 = [Adam Krzysztof Tomasz]

*** Usuwanie ***
Lista2 = [Krzysztof Tomasz]
--- Usuwam wszystkie elementy hurtem
Destruktor Element: Agnieszka
Destruktor Element: Beata
Destruktor Element: Maria
Czy Lista1 jest pusta? tak
--- Nazwa nadal istnieje, ale lista jest pusta
Lista1 = []
Lista1 = [Adam]
--- Usuwam listę element po elemencie
Lista2 = [Krzysztof Tomasz]
Destruktor Element: Krzysztof
Lista2 = [Tomasz]
Destruktor Element: Tomasz
Lista2 = []
Destruktor Element: Adam
Destruktor StudList: Lista2
Destruktor StudList: Lista1
*/

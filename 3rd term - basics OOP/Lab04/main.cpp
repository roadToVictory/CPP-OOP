/* 
Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał, a wynik jego działania był taki sam, jak podany na końcu tego pliku.

W liście jednokierunkowej, każdy obiekt poza ostatnim wskazuje   na kolejny element listy. Następnik dla ostatniego elementu jest ustawiany na NULL (nullptr), co umożliwia sprawdzenie końca listy.
Zadanie najłatwiej rozwiązać tworząc dwie struktury: reprezentującą element listy oraz właściwą strukturę listy StudList, posiadającą nazwę i trzymajacą wskaźniki na pierwszy i ostatni węzeł.
Należy zaimplementować listę jednokierunkową, służącą do przechowywania napisów (łańcuchów znaków). Napisy muszą być kopiowane do alokowanej pamięci (nie można korzystać z std::string)

Lista posiada operacje inicjacji i kasowania listy (z alokacją i zwalnianiem pamięci) a ponadto dodawania elementu na początek listy, usuwanie elementu z początku listy albo usuwanie hurtem wszystkich elementów (lista jest pusta, ale można coś do niej dodać).

Niektóre z funkcji nie zmieniają listy i z tego powodu powinny odbierać stały wskaźnik do struktury StudList.
Należy zadbać o zwolnienie pamięci przy usuwaniu elementów i czyszczeniu listy. Valgrind (make check) nie powinien wykazywać żadnych wycieków pamięci (leap) ani błędów (errors).
*/

#include "studList.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "*** Lista 1 ***" << std::endl;
    StudList list1;
    initList(&list1,"Lista1");

    char agnieszka[] = "Agnieszka";
    append(&list1, agnieszka);
    append(&list1, "Beata");
    append(&list1, "Maria");
    StudList* ptr1 = &list1;

    std::cout << ptr1->head->name << std::endl;
    std::cout << ptr1->head->next->name << std::endl;
    std::cout << ptr1->tail->name << std::endl;
  
    const StudList *ptrc=ptr1;
    std::cout << "Czy " << ptrc->name << " jest pusta? " 
              << (isEmpty(ptrc)?"Tak":"Nie") << std::endl;
    print(ptrc);

    std::cout << "\n*** Lista 2 ***" << std::endl;
    StudList list2;
    char adam[]="Adam";
    initList(&list2,"Lista2");
    append(&list2, adam);
    append(&list2, "Krzysztof");
    append(&list2, "Tomasz");
    print(&list2);

    std::cout << "\n*** Usuwanie ***" << std::endl;
    StudList* ptr2 = &list2;
    removeFirst(ptr2);
    print(ptr2);
    std::cout << "--- Usuwam wszystkie elementy hurtem" << std::endl;
    clearList(&list1);
    std::cout << "Czy " << list1.name << " jest pusta? " 
              << (isEmpty(&list1)?"tak":"nie") << std::endl;
    std::cout << "--- Nazwa nadal istnieje, ale lista jest pusta" << std::endl;     
    print(&list1);
    append(&list1, adam);
    print(ptr1);
    removeFirst(ptr1);
    clearList(&list1); //próba usunięcia pustej listy
    removeList(ptr1);
    
    std::cout << "--- Usuwam listę element po elemencie" << std::endl;   
    print(&list2);
    removeFirst(&list2);
    print(&list2);
    removeFirst(&list2);
    print(&list2);
    removeFirst(&list2);
    removeList(&list2);

}

/* Oczekiwany wynik
./main
*** Lista 1 ***
Agnieszka
Beata
Maria
Czy Lista1 jest pusta? Nie
Lista1 = [Agnieszka Beata Maria]

*** Lista 2 ***
Lista2 = [Adam Krzysztof Tomasz]

*** Usuwanie ***
Lista2 = [Krzysztof Tomasz]
--- Usuwam wszystkie elementy hurtem
Czy Lista1 jest pusta? tak
--- Nazwa nadal istnieje, ale lista jest pusta
Lista1 = []
Lista1 = [Adam]
Kasowanie Lista1
--- Usuwam listę element po elemencie
Lista2 = [Krzysztof Tomasz]
Lista2 = [Tomasz]
Lista2 = []
Kasowanie Lista2

*/
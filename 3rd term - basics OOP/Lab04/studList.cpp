#include "studList.h"

void initList(StudList *lista, const char* nazwa){
    lista->name = (char *)nazwa;
    lista->head = nullptr;
    lista->tail = nullptr;
}

void append(StudList *lista, const char *nazwa){
    Element *temp = new Element;
    temp->name = new char[strlen(nazwa)+1];
   // temp->name = nazwa;
    strcpy(temp->name,nazwa);
    temp->next = nullptr;

    if(lista->head ==nullptr){
        lista->head = temp;
        lista->tail = temp;
    }
    else{
        /*Element *last = lista->head;

        while(last->next!=nullptr)
            last = last->next;
        
        last->next = temp;        //     I metoda
        lista->tail = temp; */

        lista->tail->next = temp;   //     II metoda
        lista->tail = temp;
    }

}

bool isEmpty(const StudList *lista){
    return lista->head == nullptr;
}

void print(const StudList *lista){
    if(lista){   
      Element *temp = lista->head;

      std::cout<< lista->name << "=[";

      while(temp!=nullptr){
          std::cout<< temp->name;
          if(temp->next!=nullptr)
              std::cout<<" ";
          temp = temp->next;
      }
      std::cout<<"]"<<std::endl;
    }
}

/*void print(const StudList *lista){
    if(lista){
    Element *temp = lista->head;

    std::cout<< lista->name << "=[";

    while(temp!=nullptr){
        //std::cout<< temp->name;
        if(temp->next!=nullptr){
            std::cout<< temp->name <<" ";
            temp = temp->next;
        }
        else {
            std::cout<< temp->name;
            temp = temp->next;
            }
    }
    std::cout<<"]"<<std::endl;
    }
} */

void removeFirst(StudList *lista){
    if(lista->head!=nullptr){
        Element *temp = lista->head;
        lista->head = lista->head->next;
        delete [] temp->name;
        delete temp;
    }
}

void clearList(StudList *lista){
    while(lista->head!=nullptr)
        removeFirst(lista);
}

void removeList(StudList *lista){
    clearList(lista);
    std::cout<<"Kasowanie " << lista->name <<std::endl;
    //delete []lista->name;
    lista = nullptr;
}
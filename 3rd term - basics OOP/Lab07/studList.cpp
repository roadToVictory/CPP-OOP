#include "studList.h"

StudList::StudList(const char *name){
    _head = nullptr;
    _tail = nullptr;
    _name = new char[strlen(name)+1];
    _name = strcpy(_name, name);

  /*  for(int i=0; i<strlen(name); i++)
        *(_name+i) = *(name+i);
    _name[strlen(name)] = '\0';*/
}

StudList::~StudList(){
    std::cout<<"Destruktor StudList: "<<_name<<std::endl;

    if(_name)
        delete []_name;
}

bool StudList::isEmpty() const{
     if(_head ==nullptr)
        return true;
    else return false;
 }

void StudList::append(Element *dodac){
    if(isEmpty()){
        _head = _tail = dodac;
    }
    else{
        _tail->_next=dodac;
        _tail = dodac;
    }
}

void StudList::append(const char *name){
    Element *tmp = new Element(name);
    //append(tmp);

    if(isEmpty())
        _head = _tail = tmp;
    else{
        _tail->_next = tmp;
        _tail = tmp;
    }
}

void StudList::print() const{
    std::cout<< this->_name<<"=[";
    Element *tmp = _head;
    while(tmp!=nullptr){

      //  if(tmp!=_head)                   //dodaje przerwy PRZED wypisaniem danego imienia
      //      std::cout<<" ";

        std::cout<<tmp->_name;

        if(tmp->_next!=nullptr)       //dodaje przerwy PO wypisaniu danego imienia
            std::cout<<" ";
        tmp=tmp->_next;
    }
    std::cout<<"]"<<std::endl;
}

 Element *StudList::getFirst(){
     if(isEmpty()){
        return nullptr;
    }
    else if(_head==_tail){
        Element *tmp = _head;
        _head = _tail = nullptr;
        return tmp;
    }
    else{
        Element *tmp = _head;
    
        Element *usun = _head->_next;
        _head->_next = nullptr;

        _head=usun;

        return tmp;
    }
 }

 void StudList::clearList(){
     while(!isEmpty()){
         removeFirst();
     }
 }

 void StudList::removeFirst(){
     if(!isEmpty()){
         Element *tmp = _head;
         _head = _head->_next;
         delete tmp;
     }
 }
#include "element.h"

Element::Element(const char *name){
    _next = nullptr;
    if(name){
        _name = new char[strlen(name)+1];
        strcpy(_name, name);
    }
    else{
        _name = nullptr;
    }
}

Element::~Element(){
    std::cout<<"Destruktor Element: "<<_name<<std::endl;

    if(_name)
        delete []_name;

}
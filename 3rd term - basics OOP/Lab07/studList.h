#include <iostream>
#include <cstring>

#include "element.h"

class StudList{
    public:
        StudList(const char *name);
        ~StudList();
        void append(Element *dodac);
        void append(const char *name);
        bool isEmpty() const;
        void print() const;
        Element *getFirst();
        void clearList();
        void removeFirst();
        
        char *getName() const{
            return _name;
        }
        Element *getHead() const{
            return _head;
        }
        Element *getTail() const{
            return _tail;
        }
        

    private:
        char* _name;
        Element *_head;
        Element *_tail;
};
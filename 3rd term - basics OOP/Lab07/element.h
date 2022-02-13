#include <iostream>
#include <cstring>

class StudList;

class Element{
    friend class StudList;
    
    public:
        Element(const char *name=nullptr);
        ~Element();

        const char *getName() const{
            return _name;
        }

        Element *getNext() const{
            return _next;
        }

        void printName() const{
            std::cout<<_name;
        }

    private:
        char *_name;
        Element *_next;
};
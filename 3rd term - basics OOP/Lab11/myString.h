#include <iostream>
#include <cstring>
#include <utility>

namespace mystring{

class String{
    public:
        String()=default;
        String(const char *znaki);
        String(const String &str);
        String(String &&str); 
        ~String();
        void print(const char *znaki) const;
        bool operator ==(const char* znaki) const;
        bool operator ==(const String &str) const;
        operator char*() const;
        String& operator =(const String &str);
        String& operator =(const char *str);
        //String operator +(const char *znaki) const;
        String operator +(const char znak) const;
        String operator +(const String &str) const;

    private:
     unsigned int _dlugosc;
     char *_tekst;
     
};
    String operator*(unsigned ilosc, const String &str);
}
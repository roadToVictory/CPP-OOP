#ifndef MYSTR_H
#define MYSTR_H
#include <iostream>
#include "studList.h"


struct MyString{
    char *string;
    char *separatory;
    char *next, *begin, *end;
};
//dokumentacja
bool findSep(const char znak, const char* text);
void initMyString(MyString *split, const char *text, const char* sep=nullptr); 
char *mystrtok(MyString *split);
char *mystrcat(char *dest, const char* text1, const char sep='\0');
void addSep(MyString *split, const char* sep);
void split2list(StudList *lista, MyString *split);
char* gettok(MyString *split, int index); 
void removeMyString(MyString *split);
#endif
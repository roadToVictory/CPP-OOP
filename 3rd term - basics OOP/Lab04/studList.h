#include <iostream>
#include <cstring>

struct Element{
    char *name;
    Element *next;
};

struct StudList{
    char *name;
    Element *head;
    Element *tail;
};

void initList(StudList *lista, const char* nazwa);
void append(StudList *lista, const char *nazwa);
bool isEmpty(const StudList *lista);
void print(const StudList *lista);
void removeFirst(StudList *lista);
void clearList(StudList *lista);
void removeList(StudList *lista);
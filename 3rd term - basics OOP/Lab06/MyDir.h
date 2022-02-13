#include <iostream>
#include <string>

struct MyDir{
    std::string nazwa;
    MyDir **subfolders; //tablica wskaznikow do podfolderow
    MyDir *parent; 
};

void initDir(MyDir &drzewo, const std::string name);
void printDir(const MyDir &drzewo);
MyDir* addDir(MyDir &drzewo, const std::string name);
void addDir(MyDir &drzewo, MyDir &subfolder);
void clearDir(MyDir *drzewo);
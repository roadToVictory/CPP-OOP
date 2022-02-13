#include "MyDir.h"


void initDir(MyDir &drzewo, const std::string name){
    if(name.length()>10){
        std::cout<<"Za dluga nazwa";
        return;
    }
    if(name.length()<1){
        std::cout<<"Za krotka nazwa";
        return;
    }
    drzewo.nazwa = name;
    drzewo.subfolders = new MyDir*[1];
    *drzewo.subfolders = nullptr;       //lub (drzewo.subfolders)[0] = nullptr;
    drzewo.parent = nullptr;
}

void printDir(const MyDir &drzewo){
    static int indent = 0;
    for(int i=0; i<indent-1; i++)
        std::cout<<"   ";
    
    /*  for(int i=0; i<3*(indent-1); i++)       // II wersja
        std::cout<<" ";
    */

    if(indent!=0)
            std::cout<<"|__";
            
    std::cout<<drzewo.nazwa<<std::endl;

    int i=0;
    while (drzewo.subfolders[i] != nullptr){
        indent += 1;
        printDir(*(drzewo.subfolders[i]));
        i++;
        indent -= 1;
    }
}

MyDir* addDir(MyDir &drzewo, const std::string name){
    if(name.length()>0){
        if(name.length()>10){
            std::cout<<"za dluga nazwa: "<<name<<std::endl;
            return &drzewo;         //lub return nullptr;
        }
    
      MyDir *nowy = new MyDir;
      nowy->nazwa = name;
      nowy->subfolders = new MyDir*[1];   //alokacja pamieci na podfoldery
      nowy->subfolders[0] = nullptr;
      nowy->parent = &drzewo;
      
      int ilosc = 0;
      while(*(drzewo.subfolders+ilosc)!=nullptr){
          ilosc++;
        // drzewo.subfolders++;
      }

      MyDir **new_directory = new MyDir*[ilosc+2];
      for(int i=0; i<ilosc; i++)
          new_directory[i] = drzewo.subfolders[i];
      new_directory[ilosc] = nowy;
      new_directory[ilosc+1] = nullptr;
      delete [] drzewo.subfolders;
      
      drzewo.subfolders = new_directory;
      
      return nowy;
    }
    else std::cout<<"za krotka nazwa"<<std::endl;
    return &drzewo;
}

void addDir(MyDir &drzewo, MyDir &subfolder){
    int ilosc = 0;
    while(*(drzewo.subfolders+ilosc)!=nullptr)
        ilosc++;
    
    MyDir**new_directory = new MyDir*[ilosc+2];
    for(int i=0; i<ilosc; i++)
        new_directory[i] = drzewo.subfolders[i];

    new_directory[ilosc] = &subfolder;
    new_directory[ilosc+1] = nullptr;
    delete[] drzewo.subfolders;

    drzewo.subfolders = new_directory;
    subfolder.parent = &drzewo;
}

void clearDir(MyDir *drzewo){
    if(drzewo->parent != nullptr){
        int ilosc = 0;
        while(*(drzewo->parent->subfolders+ilosc)!=nullptr)
            ilosc++;
        
        MyDir **new_directory = new MyDir *[ilosc];
        for(int i=0, j=0; i<ilosc; i++){
            if(drzewo->parent->subfolders[i]!=drzewo){
                new_directory[j] = drzewo->parent->subfolders[i];
                j++;
            }
        }
        new_directory[ilosc] = nullptr;
        delete[]drzewo->parent->subfolders;
        drzewo->parent->subfolders = new_directory;
    }

    int ilosc = 0;
        while(*(drzewo->subfolders+ilosc)!=nullptr)
            ilosc++;
    for(int i=0; i<ilosc; i++){
        (drzewo->subfolders[i])->parent = nullptr;
        //clearDir(drzewo->subfolders[i]);
        delete drzewo->subfolders[i];
    }
    delete drzewo->subfolders;
}
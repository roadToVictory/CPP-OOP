#include "mystr.h"

bool findSep(const char znak, const char* text){
    while(*text!='\0'){
        if(*text==znak)
            return true;
        text++;
    }
    return false;
}

void initMyString(MyString *split, const char *text, const char* sep){
    split->string = mycopy(text);
    
    if(sep==nullptr)
        split->separatory = nullptr;
    else split->separatory = mycopy(sep);

    split->begin = split->string;
    split->end = split->string+mystrlen(split->string);
    split->next = split->begin;
}

char* mystrtok(MyString *split){
    char *str = split->next, *sep = split->separatory;

    while(*str=='\0' && str!=split->end)    //jezeli koniec lancucha ale nie jest to koniec calego napisu
        str++;
    
    char *w = str;
    bool find;

    while(w!=split->end){
        find = false;
        while(*sep!='\0'){
            if(*w==*sep || *w=='\0'){
                find = true;
                break;
            }
            else sep++;
        }
        if(find){
            split->next = w+1;
            break;
        }                                          
        sep = split->separatory;
        w++;
    }
    
    while(w!=split->end){
        find = true;
        while(*sep!='\0'){
            if(*w==*sep || *w=='\0'){
                find = false;
                break;
            }
            sep++;
        }
        if(!find){
            *w='\0';
            split->next = w+1;
        }
        else break;
        sep = split->separatory;
        w++;
    }

    if(w==split->end)
        split->next = split->end;

    return str;
}

char* mystrcat(char *dest, const char* text1, const char sep){
    int dlugosc = mystrlen(dest)+mystrlen(text1)+(sep=='\0'?1:0);
    char *result = new char[dlugosc+2];
    int i=0;

    while(*dest!='\0'){         // lub dest[i]
        result[i] = *dest;      //     result[i] = dest[i];
        i++;
        dest++;                 // wtedy ta linijka zbędna, podobnie można w drugiej pętli poniżej
    }   
    if(sep!='\0'){
        result[i] = sep;
        i++;
    } 
    while(*text1!='\0'){
        result[i] = *text1;
        text1++;
        i++;
    }
    result[i] = '\0';
    return result;
}

void addSep(MyString *split, const char *sep){
    if(split->separatory == nullptr)
        split->separatory = mycopy(sep);
    else split->separatory = mystrcat(split->separatory, sep);
}

void split2list(StudList *lista, MyString *split){
    char *result;
    while(split->next!=split->end){
        result = mystrtok(split);
        append(lista, result);
    }
    split->next = split->begin;
}

char* gettok(MyString *split, int index){
    char *string;
    split->next = split->begin;

    for(int i=0; i<index; i++)
        string = mystrtok(split);

    //split->next = split->begin;

    return string;
}

void removeMyString(MyString *split){
    delete[] split->string;
    
    if(split->separatory!=nullptr)
        delete[] split->separatory;
    
    split->begin = nullptr;
    split->end = nullptr;
    split->next = nullptr;
}
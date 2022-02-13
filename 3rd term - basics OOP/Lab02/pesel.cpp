#include "pesel.h"


int getControlNumber(int *pesel){
    int wagi[10] = {1,3,7,9,1,3,7,9,1,3};
    int suma =0;
    int k=0;
    for(int i=0; i<10; i++){
        suma += wagi[i]*pesel[i];
    }
    k = (10-(suma%10))%10;

    return k;
}

bool leapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


int getYear(int pesel[]){
    int kontrol = pesel[2]*10 + pesel[3];

    if(kontrol>40)
        return (pesel[0]*10 + pesel[1]+2100);
    else if (kontrol>20)
         return (pesel[0]*10 + pesel[1]+2000);
    else return (pesel[0]*10 + pesel[1]+1900);
}


void printPesel(int pesel[]){
    for(int i=0; i<11;i++)
        std::cout<<pesel[i];
}


bool Male(int *pesel){
    return (pesel[9]%2) ? 1 : 0;
}

int getDay(int pesel[]){
    return pesel[4]*10 + pesel[5];
}

int getMonth(int pesel[]){
    if(pesel[2]>3)
        return (pesel[2]*10 + pesel[3] - 40);
    else if(pesel[2]>1)
        return (pesel[2]*10 + pesel[3] - 20);
    else  return (pesel[2]*10 + pesel[3]);
}

bool dni_miesiaca(int pesel[]){
    int tablica[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(getDay(pesel)>tablica[getMonth(pesel)-1] && getMonth(pesel)==2)
        return leapYear(getYear(pesel));
    if(getDay(pesel)>tablica[getMonth(pesel)-1]) 
        return false;
    else return true;
}

bool PeselValidator(char *Tpesel, int pesel[]){
    if(strlen(Tpesel)!=11)
        return false;
    else{
        for(int i=0; i<11; i++)
            pesel[i] = Tpesel[i]-48;
    }


    return (getControlNumber(pesel)==pesel[10] && dni_miesiaca(pesel)) ? true : false;

            
}
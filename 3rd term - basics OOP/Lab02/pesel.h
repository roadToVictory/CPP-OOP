
#include <iostream>
#include <cstring>

int getControlNumber(int *pesel);
bool PeselValidator(char *Tpesel, int pesel[]);
void printPesel(int pesel[]);

bool Male(int *pesel);
int getDay(int pesel[]);
int getMonth(int pesel[]);
int getYear(int pesel[]);
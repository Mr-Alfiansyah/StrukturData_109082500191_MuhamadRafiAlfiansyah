#ifndef SLL_H
#define SLL_H
 
#include <iostream>
#define Nil NULL
 
using namespace std;
 
typedef int infotype;
typedef struct ElmList *address;
 
struct ElmList {
    infotype info;
    address next;
};
 
struct List {
    address First;
};
 
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);
 
#endif
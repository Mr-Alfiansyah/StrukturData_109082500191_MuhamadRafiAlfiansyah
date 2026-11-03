#include "DLL.h"
 
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}
 
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}
 
void dealokasi(address &P) {
    delete P;
    P = Nil;
}
 
void printInfo(List L) {
    address P = L.last;
    cout << endl << "DATA LIST 1" << endl << endl;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}
 
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}
 
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
 
void deleteFirst(List &L, address &P) {
    P = L.first;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = (L.first)->next;
        P->next = Nil;
        (L.first)->prev = Nil;
    }
}
 
void deleteLast(List &L, address &P) {
    P = L.last;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = (L.last)->prev;
        P->prev = Nil;
        (L.last)->next = Nil;
    }
}
 
void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    (P->next)->prev = Prec;
    P->prev = Nil;
    P->next = Nil;
}
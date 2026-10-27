#include "SLL.h"
 
// bikin list kosong
void CreateList(List &L) {
    L.First = Nil;
}
 
// bikin elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}
 
// hapus elemen dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}
 
// tampilkan semua info
void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}
 
// tambah elemen di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
 
// cari elemen dengan info x
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
 
// jumlahkan semua info
int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>

<p align="center">Muhamad Rafi Alfiansyah - 109082500191</p>

## Dasar Teori

Linked list adalah struktur data yang terdiri dari kumpulan node yang saling terhubung lewat pointer. Tiap node menyimpan data dan alamat node berikutnya. Berbeda dengan array yang ukurannya ditentukan di awal, linked list memakai alokasi memori dinamis sehingga jumlah elemennya bisa bertambah atau berkurang saat program berjalan [1].

### A. Singly Linked List dan ADT

Singly linked list adalah linked list yang setiap nodenya punya satu pointer `next`. Pointer itu menunjuk ke node berikutnya, dan node terakhir menunjuk ke `Nil`. Karena arahnya hanya satu, penelusuran selalu dimulai dari node pertama (`head`) sampai node terakhir (`tail`) [1]. Pada modul ini, pointer ke node pertama disimpan di `First`.

Singly linked list dibuat dalam bentuk ADT (*Abstract Data Type*), yaitu definisi tipe data beserta operasi-operasinya. Hasilnya dipisah ke tiga file: `.h` untuk deklarasi tipe dan prototype fungsi, `.cpp` untuk isi fungsinya, dan `main.cpp` untuk mencoba ADT tersebut.

Komponen yang dipakai pada praktikum ini adalah:

- `infotype`, yaitu tipe data yang disimpan pada node, berupa `int`.
- `address`, yaitu pointer ke `ElmList`.
- `ElmList`, yaitu node yang berisi `info` dan `next`.
- `List`, yaitu struktur yang berisi `First`, penunjuk node pertama.
- `Nil`, yaitu penanda pointer yang tidak menunjuk node mana pun.

Modul menjelaskan prototype ADT yang lengkap, tetapi latihan Modul 5 memakai bagian yang dibutuhkan saja, yaitu `CreateList`, alokasi, dealokasi, `printInfo`, `insertFirst`, ditambah `findElm` untuk pencarian dan satu fungsi untuk menjumlahkan seluruh info.

### B. Alokasi, Dealokasi, dan insertFirst

Node baru dibuat dengan operator `new` di fungsi alokasi, lalu `info` diisi dan `next` diset `Nil`. Kalau node sudah tidak dipakai, memorinya dikembalikan ke sistem dengan `delete` di fungsi dealokasi supaya tidak terjadi *memory leak* [1].

`insertFirst` menyisipkan node di awal list dengan dua langkah: `next` node baru diarahkan ke `First`, lalu `First` dipindah ke node baru. Karena selalu disisipkan di depan, node yang paling akhir dimasukkan akan berada di posisi paling depan, sehingga urutan list kebalik dari urutan input.

### C. Searching pada Linked List

Searching adalah proses mencari node dengan data tertentu. Node pada linked list tidak bisa diakses langsung lewat indeks seperti array, jadi pencarian dilakukan berurutan dari `First`. Pointer bantu bergerak ke node berikutnya lewat `next` sampai data ditemukan atau pointer sudah bernilai `Nil` [1].

Cara ini sama dengan *sequential search*, yaitu data dibandingkan satu per satu dari awal sampai data yang dicari ketemu atau semua data sudah diperiksa [2][3][4].

Pada latihan, fungsi `findElm` dipakai untuk mencari node dengan `info` tertentu. Kalau ketemu, fungsi mengembalikan alamat node tersebut, dan kalau tidak ketemu mengembalikan `Nil`.

### D. Penelusuran List dan Kompleksitas

Menampilkan isi list dan menjumlahkan seluruh info sama-sama memakai penelusuran dari `First` sampai `Nil`, dengan satu pointer bantu yang berpindah lewat `next`. Untuk menjumlahkan info, nilai `info` tiap node ditambahkan ke variabel penampung selama penelusuran.

Pada sequential search, kompleksitas waktu rata-rata maupun kasus terburuk adalah O(n) [2]. Pada linked list, akses ke elemen tertentu harus menelusuri dari awal sehingga kompleksitasnya O(n), sedangkan akses lewat indeks pada array adalah O(1) [1]. Sebaliknya, `insertFirst` tidak perlu menelusuri list karena hanya mengubah dua pointer.

## Guided

### 1. Implementasi Linked List Mahasiswa

**`list.h`**

```cpp
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist list, string nim);
    
address findNodeByData(linkedlist List, string data);
#endif

#endif
```

**`list.cpp`**

```cpp
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;
        list.first->isidata = newData;
    }
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list, address &prev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else if (prev == Nil || prev->next == Nil)
    {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
    else
    {
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Masukan nim baru : ";
            cin >> nodeBantu->isidata.nim;
            cout << "Masukan umur baru : ";
            cin >> nodeBantu->isidata.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address findNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas umur " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", umur : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

**`main.cpp`**

```cpp
#include "list.h"
#include <iostream>
using namespace std;

int main(){
		linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);

    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    printList(List);

    updateByNim(List, "2311102133");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);

    return 0;
}
```

Data mahasiswa dimasukkan ke dalam linked list menggunakan insertFirst(), insertLast(), dan insertAfter(). Setelah itu, program menampilkan data mahasiswa beserta jumlah node yang ada. Selanjutnya, fungsi updateFirst(), updateLast(), updateAfter(), dan updateByNim() digunakan untuk mengubah data mahasiswa berdasarkan posisi node atau NIM tertentu.

## Unguided

### 1. Implementasi ADT Singly Linked List

**`SLL.h`**

```cpp
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
```

**`SLL.cpp`**

```cpp
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
```

**`main.cpp`**

```cpp
#include "SLL.h"
 
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
 
    CreateList(L);
 
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);
 
    printInfo(L);
    cout << endl;
 
    // soal 3: cari elemen 8
    address P = findElm(L, 8);
    if (P != Nil) {
        cout << P->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    cout << endl;
 
    // soal 4: total info
    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;
 
    return 0;
}
```

#### Output Unguided 1

![Screenshot Output Unguided 1](Output/SL.png)

Angka 2, 0, 8, 12, dan 9 dimasukkan ke dalam linked list menggunakan insertFirst(). Karena setiap angka dimasukkan ke bagian awal, urutan datanya menjadi 9, 12, 8, 0, dan 2. Fungsi findElm() digunakan untuk mencari angka 8, sedangkan totalInfo() digunakan untuk menghitung jumlah seluruh data yang menghasilkan nilai 31.

## Kesimpulan

Dari praktikum ini, aku jadi paham cara kerja singly linked list, mulai dari membuat node, menambahkan data dengan insertFirst(), mencari data dengan findElm(), sampai menjumlahkan seluruh data dengan totalInfo(). Karena insertFirst() menambahkan data di awal, urutan output menjadi terbalik dari urutan input. Hasil pencarian angka 8 berhasil ditemukan, sedangkan total seluruh data adalah 31.

## Referensi

[1] R. D. Setiyawan, D. Hermawan, A. F. Abdillah, A. Mujayanah, dan R. Vindua. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. *JUTECH: Journal Education and Technology, 5*(2). https://doi.org/10.31932/jutech.v5i2.4263

[2] F. Assegaf, A. Suharso, dan A. Primajaya. (2023). Penerapan Algoritma Sequential Search pada Website Yayasan Nurul Iman Perum Taman Singaperbangsa Karawang. *JATI (Jurnal Mahasiswa Teknik Informatika), 7*(5), 3555–3564.

[3] A. Sonita dan M. Sari. (2018). Implementasi Algoritma Sequential Searching untuk Pencarian Nomor Surat pada Sistem Arsip Elektronik. *Pseudocode, 5*(1), 1–9. https://doi.org/10.33369/pseudocode.5.1.1-9

[4] Y. Religia. (2019). Analisis Algoritma Sequential Search dan Binary Search pada Big Data. *Pelita Teknologi: Jurnal Ilmiah Informatika, Arsitektur dan Lingkungan, 14*(1), 74–79.

[5] D. Markuci dan C. Prianto. (2022). Analisis Perbandingan Penggunaan Algoritma Sequential Search dan Binary Search pada Aplikasi Surat Perjalanan Dinas. *JATI (Jurnal Mahasiswa Teknik Informatika), 6*(1), 110–119. https://doi.org/10.36040/jati.v6i1.4569

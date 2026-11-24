# <h1 align="center">Laporan Praktikum Modul 7 - STACK (BAGIAN PERTAMA)</h1>

<p align="center">Muhamad Rafi Alfiansyah - 109082500191</p>

## Dasar Teori

### A. Stack

Stack adalah struktur data linear yang menerapkan prinsip LIFO (Last In First Out), artinya data yang terakhir masuk akan jadi yang pertama keluar. Gampangnya seperti tumpukan piring, kita cuma bisa menaruh piring baru di paling atas dan mengambil juga dari paling atas. Karena itu semua operasi pada stack hanya terjadi di satu ujung, yang disebut top. Kalau mau mengambil data yang ada di bawah, data di atasnya harus dikeluarkan dulu.

### B. Stack dengan Array

Pada praktikum ini stack dibuat dengan ADT berbasis array. Stack disusun dari array info yang berisi maksimal 20 elemen dan variabel top yang menandai posisi elemen paling atas. Saat stack baru dibuat (createStack), top bernilai 0 yang berarti stack kosong. Operasi push menambah nilai top lebih dulu, baru data disimpan di info[top], sedangkan pop mengambil data di info[top] lalu mengurangi nilai top. Kalau stack sudah penuh lalu di-push terjadi overflow, dan kalau stack kosong lalu di-pop terjadi underflow. Keduanya perlu dicek. Kelebihannya implementasinya simpel dan hemat memori karena tidak butuh pointer, kekurangannya ukuran stack tetap sehingga tidak bisa bertambah saat program berjalan. Operasi push dan pop sama-sama O(1).

### C. Operasi pada Latihan

Selain push dan pop, ada beberapa operasi lain. printInfo menampilkan isi stack dari top ke bawah, jadi urutan tampilnya kebalikan dari urutan masuk. balikStack membalik isi stack dengan menukar elemen paling bawah dan paling atas, bergerak ke tengah sampai selesai. pushAscending menyisipkan data sambil menjaga stack tetap terurut naik dari bawah ke atas, caranya dengan menggeser elemen yang lebih besar dari data baru ke atas dulu. Terakhir, getInputStream membaca input user per karakter memakai cin.get() dan langsung mem-push setiap karakternya sampai user menekan enter.


## Guided 1

### 1. Stack

**`stack.h`**

```cpp
#ifndef STACK_TABLE
#define STACK_TABLE
#include <iostream>
using namespace std;
const int MAX = 10;

struct stackTable
{
    int data[MAX];
    int top;
};
bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s); 
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);
#endif
```

**`stack.cpp`**

```cpp

#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data" << angka << "berhasil ditambahkan kedalam stack !" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data" << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```

**`main.cpp`**

```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    update(s, 2);
    update(s, 1);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```

Membuat stack dengan representasi array berukuran maksimal 10, dengan top sebagai penanda elemen paling atas dan nilai -1 yang berarti stack masih kosong. Stack dibuat dulu lewat createStack, lalu diisi angka 1 sampai 5 menggunakan push dan ditampilkan dengan view dari top ke bawah. Setelah itu dilakukan pop dua kali sehingga dua data teratas terhapus, kemudian update dipakai untuk mengubah data berdasarkan posisinya yang dihitung dari top, yaitu posisi ke-2 dan ke-1 dengan nilai baru yang diinput user. Terakhir, searchData mencari angka 4 dan 9, lalu menampilkan posisinya kalau ketemu atau pesan tidak ditemukan kalau tidak ada. Setiap operasi dicek dulu dengan isEmpty dan isFull supaya tidak terjadi underflow maupun overflow.

## Guided 2

### 2. Stack

**`stack.h`**

```cpp
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;
const int MAX = 10;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(addresss &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack); 
void update(stack &listStack, int posisi);
void view(stack &listStack);
void searchData(stack listStack, int data);
#endif
```

**`stack.cpp`**

```cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count < posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

**`main.cpp`**

```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Membuat stack dengan representasi linked list, jadi setiap data disimpan dalam node yang punya dataAngka dan pointer next, sedangkan top menunjuk node paling atas dan bernilai Nil kalau stack kosong. Node dibuat dulu dengan alokasi, lalu dimasukkan lewat push yang menaruh node baru di atas top, sehingga pada main angka 1 sampai 5 masuk berurutan dan isinya ditampilkan dari 5 ke 1 oleh view. Operasi pop menghapus node paling atas dengan memindahkan top ke node berikutnya lalu melepas memorinya dengan dealokasi, dan dilakukan dua kali sehingga tersisa tiga node. Setelah itu update mengubah data berdasarkan posisi yang dihitung dari top dengan menelusuri pointer next, dan posisi ke-4 dinyatakan tidak valid karena node yang tersisa hanya tiga. Terakhir, searchData menelusuri node dari top untuk mencari angka 4 dan 9, lalu menampilkan posisinya kalau ketemu atau pesan tidak ditemukan kalau tidak ada.

## Unguided

### 1.  ADT Stack menggunakan ARRAY 

**`stack.h`**

```cpp
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

```

**`stack.cpp`**

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top = S.top + 1;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = 0;
    if (S.top > 0) {
        x = S.info[S.top];
        S.top = S.top - 1;
    } else {
        cout << "Stack kosong" << endl;
    }
    return x;
}

void pushAscending(Stack &S, int x) {
    if (S.top < 19) {
        int i = S.top;
        while (i >= 1 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }
        S.info[i + 1] = x;
        S.top = S.top + 1;
    } else {
        cout << "Stack penuh" << endl;
    }
}

void getInputStream(Stack &S) {
    char c;
    c = cin.get();
    while (c != '\n') {
        push(S, c - '0');
        c = cin.get();
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        cout << S.info[i];
        if (i > 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 1;
    int j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

```

**`main.cpp`**

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    cout << endl << "Soal 1" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    cout << endl << "Soal 2" << endl;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    cout << endl << "Soal 3" << endl;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```

#### Output Unguided

![Screenshot Output Unguided 1](Output/S1.png)

Membuat ADT Stack dengan array berukuran 20 yang dilengkapi variabel top sebagai penanda elemen paling atas. Stack dibuat kosong lewat createStack dengan nilai top 0, lalu data ditambahkan memakai push dan dikeluarkan memakai pop sesuai prinsip LIFO. Pada main, data 3, 4, dan 8 dimasukkan, lalu 8 di-pop, 2 dan 3 dimasukkan, 3 di-pop lagi, dan terakhir 9 dimasukkan. Isi stack ditampilkan dengan printInfo dari top ke bawah sehingga hasilnya 9 2 4 3, kemudian dibalik dengan balikStack dan ditampilkan lagi menjadi 3 4 2 9.

![Screenshot Output Unguided 2](Output/S2.png)

Ditambahkan prosedur pushAscending untuk memasukkan data sambil menjaga isi stack tetap terurut naik dari bawah ke atas. Saat data baru masuk, elemen di atasnya yang lebih besar digeser satu posisi ke atas dulu, lalu data baru disimpan di posisi yang kosong tadi dan top bertambah satu. Data 3, 4, 8, 2, 3, dan 9 dimasukkan dengan cara ini sehingga saat ditampilkan dari top hasilnya 9 8 4 3 3 2. Setelah stack dibalik dengan balikStack, urutan tampilnya menjadi 2 3 3 4 8 9.

![Screenshot Output Unguided 3](Output/S3.png)

Ditambahkan prosedur getInputStream yang membaca input dari user satu karakter demi satu memakai cin.get(). Setiap karakter yang dibaca diubah menjadi angka lalu langsung dimasukkan ke stack dengan push, dan proses ini berhenti ketika user menekan enter. Sebagai contoh, input 4729601 akan tersimpan berurutan sehingga printInfo menampilkannya dari top menjadi 1 0 6 9 2 7 4. Setelah dibalik dengan balikStack, hasilnya kembali sama dengan urutan input, yaitu 4 7 2 9 6 0 1.

## Kesimpulan

Saya jadi lebih memahami cara kerja Stack dan bagaimana struktur data ini menyimpan serta mengelola data dengan prinsip LIFO. Saya belajar membuat ADT Stack dengan array, mulai dari createStack, push, pop, sampai menampilkan isi stack dengan printInfo. Saya juga memahami peran top sebagai penanda elemen paling atas yang berubah setiap kali data ditambah atau dihapus. Selain itu, saya belajar membalik isi stack dengan balikStack, menyisipkan data secara terurut dengan pushAscending, dan memasukkan input user ke stack dengan getInputStream. Melalui praktikum ini, saya dapat lebih memahami penerapan Stack dalam program C++.

## Referensi

[1] OpenDSA. (t.t.). Stacks. https://opendsa-server.cs.vt.edu/ODSA/Books/CS2/html/StackArray.html

[2] GeeksforGeeks. (t.t.). Stack Data Structure. https://www.geeksforgeeks.org/dsa/stack-data-structure/

[3] Programiz. (t.t.). Stack Data Structure. https://www.programiz.com/dsa/stack

[4] Setiyawan, R. D., dkk. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH, 5(2). https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pdf

# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>

<p align="center">Muhamad Rafi Alfiansyah - 109082500191</p>

## Dasar Teori

### A. Queue

Queue adalah struktur data linear yang menerapkan prinsip FIFO (First In First Out), artinya data yang pertama masuk akan jadi yang pertama keluar. Gampangnya seperti antrean di loket tiket kereta api: orang yang datang duluan dilayani duluan, dan yang datang paling akhir dilayani paling akhir. Beda dengan stack yang cuma punya satu ujung, queue punya dua ujung. Ujung depan disebut head, tempat elemen diambil, dan ujung belakang disebut tail, tempat elemen baru ditambahkan.

### B. Operasi Dasar Queue

Ada dua operasi utama pada queue. Yang pertama enqueue (insert), yaitu menyisipkan elemen baru di bagian tail. Yang kedua dequeue (delete), yaitu mengambil dan menghapus elemen di bagian head. Selain itu ada operasi pendukung seperti createQueue untuk membuat queue kosong, isEmpty untuk mengecek apakah queue kosong, isFull untuk mengecek apakah queue penuh (khusus representasi tabel), dan printInfo untuk menampilkan isi queue. Karena penyisipan dan penghapusan terjadi di ujung yang berbeda, kita harus selalu menjaga head dan tail tetap benar setelah setiap operasi, termasuk saat queue berubah dari kosong ke satu elemen atau sebaliknya.

### C. Queue dengan Linked List

Pada representasi pointer, queue dibuat dari linked list yang punya dua penunjuk, head dan tail. Queue dianggap kosong kalau head bernilai Nil. Saat enqueue, elemen baru dialokasikan dulu, lalu next dari tail lama diarahkan ke elemen baru, kemudian tail dipindahkan ke elemen itu. Saat dequeue, head dipindahkan ke elemen berikutnya, lalu elemen lama dilepas dengan mengisi next-nya dengan Nil. Kelebihannya jumlah antrean tidak terbatas karena memorinya dialokasikan sesuai kebutuhan. Kekurangannya kita harus mengelola memori sendiri lewat alokasi dan dealokasi.

### D. Queue dengan Tabel (Array)

Pada representasi tabel, queue disimpan dalam array dengan ukuran tetap, sehingga jumlah antrean terbatas, tapi tidak perlu manajemen memori. Di modul ini ada tiga alternatif cara mengelola head dan tail:

1. **Alternatif 1 (head diam, tail bergerak).** Head selalu berada di indeks awal selama queue tidak kosong. Enqueue cukup memajukan tail. Dequeue mengambil elemen head, lalu semua elemen sesudahnya digeser maju satu langkah dan tail mundur. Cara ini mirip orang yang maju satu per satu di antrean sungguhan, tapi kurang efisien karena ada proses pergeseran di setiap dequeue.

2. **Alternatif 2 (head bergerak, tail bergerak).** Saat dequeue, head yang maju, jadi tidak ada pergeseran elemen dan lebih efisien. Masalahnya, bisa muncul kondisi penuh semu, yaitu tail sudah di indeks maksimum padahal bagian depan array masih kosong. Kalau itu terjadi, elemen harus digeser dulu supaya ada ruang, dan pergeseran ini hanya dilakukan kalau tail sudah mencapai indeks maksimum.

3. **Alternatif 3 (head dan tail berputar).** Head dan tail bergerak melingkar di sepanjang array. Kalau tail sudah di indeks maksimum, penerusnya kembali ke indeks awal selama masih ada tempat kosong. Cara ini disebut circular buffer, dan paling efisien karena tidak perlu pergeseran sama sekali, sekaligus menghilangkan masalah penuh semu.

Ketiganya punya aturan yang sama untuk kondisi khusus. Queue kosong ditandai dengan head dan tail bernilai -1 (pada latihan), dan saat dequeue terakhir menghabiskan elemen, head dan tail dikembalikan ke kondisi kosong.

### E. Operasi pada Latihan

Latihan memakai ADT Queue berbasis array dengan 5 elemen bertipe integer dan variabel head serta tail. Operasinya meliputi createQueue untuk membuat queue kosong dengan head dan tail bernilai -1, isEmptyQueue dan isFullQueue untuk mengecek kondisi queue, enqueue untuk menambah elemen di tail, dequeue untuk mengambil elemen di head dan mengembalikan nilainya, serta printInfo untuk menampilkan posisi head, tail, dan isi queue dari depan ke belakang (atau tulisan "empty queue" kalau kosong). Ketiga alternatif diimplementasikan pada file queue.cpp dengan file queue.h dan program utama yang sama, sehingga kita bisa membandingkan perilaku masing-masing mekanisme dari output yang dihasilkan.

## Guided 1

### 1. Guided Queue Representasi Linked List

**`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;
const int MaxQueue = 20;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node *head, *tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enqueue(queue &Q, const string &nama);
void dequeue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);
#endif
```

**`queue.cpp`**

```cpp
#include "queue.h"

void createQueue(queue &Q){
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty(queue Q){
    return (Q.head == NULL && Q.tail == NULL);
}

bool isFull(queue Q){
    Node *nodeBantu = Q.head;
    int count = 0;
    while(nodeBantu != NULL){
        count++;
        nodeBantu = nodeBantu->next;
    }
    return (count >= MaxQueue);
}

void enqueue(queue &Q, const string &nama){
    if(isEmpty(Q)){
        Node *nodeBaru = new Node{nama, NULL};
        Q.head = nodeBaru;
        Q.tail = nodeBaru;
    }else {
        Node *nodeBantu = new Node{nama, NULL};
        Q.tail->next = nodeBantu;
        Q.tail = nodeBantu;
    }
}

void dequeue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        Node *nodeHapus = Q.head;
        Q.head = Q.head->next;
        if(Q.head == NULL){
            Q.tail = NULL;
        }
        delete nodeHapus;
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        Node *nodeBantu = Q.head;
        while(nodeBantu != NULL){
            cout << "Nama : " << nodeBantu->nama << " ";
            nodeBantu = nodeBantu->next;
        }
        cout << endl;
    }
}

void clearQueue(queue &Q){
    while(!isEmpty(Q)){
        dequeue(Q);
    }
}
```

**`main.cpp`**

```cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main (){
    queue Q;
    createQueue(Q);

    enqueue(Q, "Dominic");
    enqueue(Q, "Torr");
    enqueue(Q, "Retto");
    enqueue(Q, "Letty");
    enqueue(Q, "Brian");
    enqueue(Q, "Mia");
    cout << "Isi Queue sebelum di dequeue: " << endl;
    viewQueue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    cout << "Isi Queue setelah di dequeue: " << endl;
    viewQueue(Q);
    return 0;
}
```

Program ini membuat queue dengan representasi linked list, di mana setiap elemen berupa node yang menyimpan nama dan penunjuk next, sedangkan queue dipegang oleh pointer head (depan) dan tail (belakang) dan dianggap kosong kalau keduanya NULL. Setelah dibuat lewat createQueue, enqueue menambahkan node baru di belakang dengan mengaitkan next dari tail lama ke node baru lalu memindahkan tail, sementara dequeue menghapus node di depan dengan memajukan head dan mengembalikan tail ke NULL kalau queue jadi kosong. Di main, enam nama (Dominic sampai Mia) dimasukkan lalu ditampilkan dengan viewQueue, kemudian dequeue dipanggil empat kali sehingga empat nama terdepan keluar lebih dulu sesuai prinsip FIFO dan tersisa Brian dan Mia. Fungsi clearQueue dan isFull melengkapi program untuk mengosongkan queue dan mengecek batas MaxQueue sebesar 20.

## Guided 2

### 2. Guided Queue Representasi Array

**`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

**`queue.cpp`**

```cpp
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] = Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i - Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}
```

**`main.cpp`**

```cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini membuat queue dengan representasi array berukuran maksimal 5 (MAKSIMAL), di mana nama disimpan dalam array dan dua penanda head serta tail yang bernilai -1 saat queue kosong. Setelah dibuat lewat CreateQueue, enQueue menambahkan nama di posisi tail yang dimajukan satu langkah (kalau masih kosong, head dan tail langsung diset ke 0), sedangkan queue dianggap penuh kalau tail sudah mencapai indeks terakhir sehingga data berikutnya ditolak dengan pesan penuh. Pada deQueue, head tetap diam di indeks 0: semua elemen digeser maju satu langkah untuk menimpa elemen terdepan lalu tail dimundurkan, dan kalau tail jadi kurang dari 0 maka head dan tail dikembalikan ke -1 (kosong). Di main, enam nama dimasukkan sehingga Daffa gagal masuk karena queue sudah penuh oleh lima nama pertama, lalu viewQueue menampilkannya, kemudian deQueue dipanggil empat kali sehingga empat nama terdepan keluar lebih dulu sesuai prinsip FIFO dan tersisa Fathur saja. Mekanisme ini sesuai Alternatif 1 (head diam, tail bergerak), yang mudah dipahami tapi kurang efisien karena setiap dequeue butuh pergeseran elemen.

## Unguided

### 1.  Soal 1 - Alternatif 1: `Head` Diam dan `Tail` Bergerak 

**`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

**`queue.cpp`**

```cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < Q.head) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

**`main.cpp`**

```cpp
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```

### 2. Soal 2 - Alternatif 2: `Head` dan `Tail` Bergerak

**`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

**`queue.cpp`**

```cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.head == 0 && Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        if (Q.tail == MAX - 1) {
            int n = Q.tail - Q.head + 1;
            for (int i = 0; i < n; i++) {
                Q.info[i] = Q.info[Q.head + i];
            }
            Q.head = 0;
            Q.tail = n - 1;
        }
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

**`main.cpp`**

```cpp
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### 3. Soal 3 - Alternatif 3: `Head` dan `Tail` Berputar

**`queue.h`**

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

**`queue.cpp`**

```cpp
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return !isEmptyQueue(Q) && (Q.tail + 1) % MAX == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    int n = (Q.tail - Q.head + MAX) % MAX + 1;
    int i = Q.head;
    for (int k = 0; k < n; k++) {
        cout << Q.info[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```

**`main.cpp`**

```cpp
#include "queue.h"

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

```

#### Output Unguided

![Screenshot Output Unguided 1](Output/S1.png)

Pake Alternatif 1 yaitu head diam di indeks 0 dan tail bergerak. Queue berupa array berukuran 5 dengan head dan tail bernilai -1 saat kosong. Enqueue memajukan tail lalu menyimpan data, sedangkan dequeue menggeser semua elemen maju satu langkah dan memundurkan tail. Queue penuh kalau tail sudah di indeks terakhir. Cara ini sederhana tapi kurang efisien karena ada pergeseran di setiap dequeue.

![Screenshot Output Unguided 2](Output/S2.png)

Pake Alternatif 2, yaitu head dan tail sama-sama bergerak. Dequeue cukup memajukan head tanpa menggeser elemen, jadi lebih efisien. Konsekuensinya bisa muncul penuh semu, yaitu tail sudah di indeks terakhir padahal bagian depan array kosong. Karena itu elemen baru digeser ke depan di enqueue, hanya kalau tail sudah mencapai indeks terakhir. Queue benar-benar penuh kalau head = 0 dan tail = MAX - 1.

![Screenshot Output Unguided 3](Output/S3.png)

Pake Alternatif 3, yaitu head dan tail berputar (circular buffer). Setelah indeks terakhir, keduanya kembali ke indeks 0 lewat operasi modulo (% MAX), jadi tidak perlu pergeseran dan tidak ada penuh semu. Queue penuh kalau (tail + 1) % MAX == head. Cara ini paling efisien dari ketiga alternatif.

## Kesimpulan

Dari praktikum ini saya jadi lebih paham cara kerja Queue dan prinsip FIFO, yaitu data yang pertama masuk akan keluar lebih dulu. Saya belajar membuat Queue dengan representasi linked list dan array, mulai dari createQueue, enqueue, dequeue, sampai menampilkan isinya dengan viewQueue atau printInfo. Saya juga memahami peran head dan tail sebagai penanda ujung depan dan belakang antrean, serta bagaimana keduanya harus dijaga tetap benar, termasuk saat queue kosong. Pada representasi array, saya membandingkan tiga alternatif: Alternatif 1 sederhana tapi kurang efisien karena ada pergeseran di setiap dequeue, Alternatif 2 lebih efisien tapi bisa mengalami penuh semu, dan Alternatif 3 dengan circular buffer paling efisien karena tidak butuh pergeseran. Sementara itu, linked list tidak punya batas jumlah elemen tapi memori harus dikelola sendiri. Melalui praktikum ini, saya dapat lebih memahami penerapan Queue dalam program C++.

## Referensi

[1] Laboratorium Informatika. (t.t.). Modul 8: Queue. Modul Praktikum Struktur Data. Fakultas Informatika, Telkom University.

[2] OpenDSA. (t.t.). Queues. https://opendsa-server.cs.vt.edu/ODSA/Books/CS2/html/QueueArray.html

[3] GeeksforGeeks. (t.t.). Queue Data Structure. https://www.geeksforgeeks.org/dsa/queue-data-structure/

[4] Programiz. (t.t.). Queue Data Structure. https://www.programiz.com/dsa/queue
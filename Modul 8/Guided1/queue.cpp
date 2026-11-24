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
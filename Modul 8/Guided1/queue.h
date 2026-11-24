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
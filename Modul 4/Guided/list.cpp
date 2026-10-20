#include "List.h"
#include <iostream>
using namespace std;

bool isEmpty(LinkedList List)
{
 if (List.first == NIL)
 {
    return true;
 }
 else
 {
    return false;
 }
}

void createList(LinkedList &List)
{
    List.first = NIL;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = "nama";
    nodeBaru->isidata.nim = "nim";
    nodeBaru->isidata.umur = "umur";
    nodeBaru->next = NIL;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = NIL;
    delete node;
}

void insertFirst(LinkedList &List, address nodeBaru)
{
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address prev)
{
    if(prev != NIL)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBaru = List.first;
        while (nodeBaru->next != NIL)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(LinkedList &List)
{
    address nodeHapus;
    if (!isEmpty(List)== false)
    {
        nodeHapus = List.first;
        nodeHapus->next = NIL;
        delaokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List)
{
    address nodeHapus, nodePrev;
    if (!isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == NIL)
        {
            List.first->next = NIL;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != NIL)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NIL;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != NIL && nodePrev->next != NIL)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = NIL;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid." << endl;
        }
    }
}
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist  List)
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

void createList(linkedlist &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
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

void delFirst(linkedlist &List)
{
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
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
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

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
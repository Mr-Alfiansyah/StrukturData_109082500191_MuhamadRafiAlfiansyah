#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "array a" << endl;
    tampilArray(a);
    cout << "array b" << endl;
    tampilArray(b);

    tukarArray(a, b, 1, 1);
    cout << "setelah tukar posisi" << endl;
    cout << "array a" << endl;
    tampilArray(a);
    cout << "array b" << endl;
    tampilArray(b);

    cout << "sebelum tukar : x = " << *p1 << ", y = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "sesudah tukar : x = " << *p1 << ", y = " << *p2 << endl;
    return 0;
}
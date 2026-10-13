#include <iostream>
#include "simpan.h"
using namespace std;

int main()
{
    mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa = ";
    cin >> n;

    if (n < 1 || n > 10)
    {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        inputMhs(mhs[i]);
    }

    cout << "\nData Mahasiswa" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Nama = " << mhs[i].nama << endl;
        cout << "NIM = " << mhs[i].nim << endl;
        cout << "Nilai Akhir = " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
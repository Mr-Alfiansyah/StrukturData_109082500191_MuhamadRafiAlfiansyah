#ifndef SIMPAN_H
#define SIMPAN_H

#include <string>
using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputMhs(mahasiswa &m);
float hitungNilaiAkhir(float uts, float uas, float tugas);

#endif
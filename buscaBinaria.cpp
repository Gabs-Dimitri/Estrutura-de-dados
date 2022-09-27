#include <iostream>
#include <vector>

using namespace std;

int Busca_Binaria(int* vetor, int elemento, int p, int r) {
    while (p<=r) {
        int q = (p+r)/2;
        if (vetor[q]< elemento) p = q+1; else
        if (vetor[q]> elemento) r = q-1; else
        if (vetor[q]==elemento) return q;
    }
    return -1;
}

int Busca_Binaria_Rec(int* vetor, int elemento, int p, int r) {
    if (p>r) return -1;
    int q = (p+r)/2;
    if (elemento<vetor[q]) return Busca_Binaria_Rec(vetor,elemento,p,q-1);
    if (elemento>vetor[q]) return Busca_Binaria_Rec(vetor,elemento,q+1,r);
    return q;
}
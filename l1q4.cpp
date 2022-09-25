#include <iostream>
#include <vector>

using namespace std;

void trocar(int& x, int& y){int z = x; x = y; y = z;}

void min_heapify(int* vetor, int i, int p, int r) {
    int m = i;
    int esq = 2*i-r-1;
    int dir = esq-1;
    if ((esq>=p)&&(vetor[esq]<vetor[i])) m = esq;
    if ((dir>=p)&&(vetor[dir]<vetor[m])) m = dir;
    if (m != i) {
        trocar(vetor[i], vetor[m]);
        min_heapify(vetor,m,p,r);
    }
}

void HeapSort_min(int* vetor, int p, int r) {
    int i;
    for (i=(r+p+2)/2; i<=r; i++) {
        min_heapify(vetor,i,p,r);
    }
    for (i=p;i<r;i++) {
        trocar(vetor[r], vetor[i]);
        p = p+1;
        min_heapify(vetor,r,p,r);
    }
}
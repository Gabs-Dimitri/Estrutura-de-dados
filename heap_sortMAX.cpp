#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>

using namespace std;

void HeapSort(int* vetor, int p, int r);

void trocar (int& x, int& y){
    int z = x;
    x = y;
    y = z;
}

void maxHeapify(int* vetor, int i, int p, int r){
    int m = i;
    int esq = 2*p + 1;
    int dir = esq + 1;
    if((esq <= r) && (vetor[esq] > vetor[i]))
        m = esq;
    if((dir <= r) && (vetor[dir] > vetor[i]))
        m = dir;
    if(m != i) {
        trocar(vetor[i], vetor[m]);
        maxHeapify(vetor, m, p, r);
    }
}

void heap_sort(int* vetor, int p, int r){
    int i;
    for(i = (r+p-1)/2; i >= p; i++){
        maxHeapify(vetor, i, p, r);
    }
    for(i = r; i > p; i--){
        trocar(vetor[p], vetor[i]);
        r = r-1;
        maxHeapify(vetor, p, p, r);
    }
}

int main(){
    int N = 2000000;
    int* vetor = new int [N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        vetor[i] = rand() % 10000;
    }
    HeapSort(vetor, 0, N-1);
}
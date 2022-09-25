#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void trocar(int& x, int& y) {int z = x; x = y; y = z;}

void maxheapify(int* vetor, int i, int p, int r) {
    int m = i;
    int esq = p+2*(i-p)+1;
    int dir = p+2*(i-p)+2;
    if ((esq<=r)&&(vetor[esq]>vetor[i])) m = esq;
    if ((dir<=r)&&(vetor[dir]>vetor[m])) m = dir;
    if (m != i) {
        trocar(vetor[i], vetor[m]);
        maxheapify(vetor,m,p,r);
    }
}
void HeapSort(int* vetor, int p, int r) {
    int i;
    for (i=(r+p-1)/2; i>=p; i--) {
        maxheapify(vetor,i,p,r);
    }
    for (i=r;i>p;i--) {
        trocar(vetor[p], vetor[i]);
        r = r-1;
        maxheapify(vetor,p,p,r);
    }
}

void Questao3(int N) {
	int* vetor = new int [N];
	srand(time(NULL));
	cout<<"Vetor original: ";
	for (int i = 0; i<N; i++) {
        vetor[i] = rand() % 1000;
        cout<<vetor[i]<<" ";
	}
	cout<<"\n\n";
	cout<<"Vetor ord parcial: ";

	HeapSort(vetor,N/3,2*N/3);
	for (int i = 0; i<N; i++) cout<<vetor[i]<<" ";
	cout<<"\n\n";
	delete[] vetor;
}

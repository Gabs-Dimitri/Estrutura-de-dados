#include <iostream>
#include <vector>

using namespace std;

typedef struct deque_1 {
    int* vet;
    int ini, fim;// pilha topo
    int num, tam;// numero de elementos e tamanho maximo
} deque_1;

void Push(deque_1& D, int x, bool bfim) {
    if (D.num==D.tam) {cout<<"Deque_1 cheio\n"; return;}
    D.num++;
    if (bfim) {
        D.fim++; if (D.fim>D.tam) D.fim=1;
        D.vet[D.fim] = x;
    } else {
        D.ini--; if(D.ini<=0) D.ini=D.tam;
        D.vet[D.ini] = x;
    }
}
int Pop(deque_1& D, bool bfim) {
    if (D.num<=0) {cout<<"Deque_1 vazio"; return -1;}
    D.num--;
    int x;
    if (bfim) {
        x = D.vet[D.fim];
        D.fim--; if(D.fim<=0) D.fim=D.tam;
    } else {
        x = D.vet[D.ini];
        D.ini++; if(D.ini>D.tam) D.ini=1;
    }
    return x;
}
void Create(deque_1& D, int N) {
    D.vet = new int[N+1];
    D.ini = 1; D.fim = N;
    D.tam = N; D.num = 0;
}
void Delete(deque_1& D) {
    if (D.vet!=NULL) delete[] D.vet;
}
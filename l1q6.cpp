#include <iostream>
#include <vector>

using namespace std;

typedef struct pilhadupla {
    int* vet;//pilha de inteiros
    int topo1, topo2;// pilha topo
    int tam;// pilha tamanho
} pilha;

bool pilha1_vazia(pilhadupla& P) {
    if (P.topo1<=0) return true;
    return false;
}

bool pilha2_vazia(pilhadupla& P) {
    if (P.topo2>P.tam) return true;
    return false;
}

bool pilha_cheia(pilha& P) {
    if (P.topo1+1>=P.topo2) return true;
    return false;
}

bool Push_1(pilhadupla& P, int x) {
    if (pilha_cheia(P)) return false;
    P.vet[++P.topo1] = x;
    return true;
}

int Pop_1(pilhadupla& P) {
    if (pilha1_vazia(P)) {
        cout << "Pilha Vazia (estouro negativo)" << endl;
        return -1;
    }
    return P.vet[P.topo1--];
}

bool Push_2(pilhadupla& P, int x) {
    if (pilha_cheia(P)) return false;
    P.vet[--P.topo2] = x;
    return true;
}

int Pop_2(pilhadupla& P) {
    if (pilha2_vazia(P)) {
        cout << "Pilha Vazia (estouro negativo)" << endl;
        return -1;
    }
    return P.vet[P.topo2++];
}
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node {
    int valor;
    node* pai;  // node pai
    node* fesq; // filho esquerdo
    node* fdir; // filho direito
};
node* raiz;

// Lista os elementos por Nivel
void nivel_ordem() {
    if (raiz==NULL) return;

    queue<node*> Q;
    Q.push(raiz);

    while (!Q.empty()) {
        node* noh = Q.front();
        Q.pop();
        if (noh!=NULL) {
            cout << noh->valor << " ";
            if (noh->fesq!=NULL) Q.push(noh->fesq);
            if (noh->fdir!=NULL) Q.push(noh->fdir);
        }
    }
}


// Lista os elementos em Pre-Ordem usando Pilha (Nao recursivo)
void pre_ordem_nao_rec() {
    if (raiz==NULL) return;

    stack<node*> Q;
    Q.push(raiz);

    while (!Q.empty()) {
        node* noh = Q.top();
        Q.pop();
        if (noh!=NULL) {
            cout << noh->valor << " ";
            if (noh->fdir!=NULL) Q.push(noh->fdir);
            if (noh->fesq!=NULL) Q.push(noh->fesq);
        }
    }
}
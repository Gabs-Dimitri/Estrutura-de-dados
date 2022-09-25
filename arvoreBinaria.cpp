#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct node {
    int valor;
    node* pai;
    node* fesq;
    node* fdir;
};

class arvore_bin{
    node* raiz;
    void pre_ordem(node* p);
    void pos_ordem(node* p);
    void em_ordem(node* p);
public: 
    void pre_ordem();
    void pos_ordem();
    void em_ordem();
    void pre_ordem_nao_rec();
    void por_nivel();
};

// Lista os elementos em PRE-Ordem
void arvore_bin::pre_ordem() {pre_ordem(raiz);}
void arvore_bin::pre_ordem(node* p) {
    if (p==NULL) return;
    cout << p->valor << " ";
    pre_ordem(p->fesq);
    pre_ordem(p->fdir);
}

// Lista os elementos em POS-Ordem
void arvore_bin::pos_ordem() {pos_ordem(raiz);}
void arvore_bin::pos_ordem(node* p) {
    if (p==NULL) return;
    pos_ordem(p->fesq);
    pos_ordem(p->fdir);
    cout << p->valor << " ";
}

// Lista os elementos em EM-Ordem
void arvore_bin::em_ordem() {em_ordem(raiz);}
void arvore_bin::em_ordem(node* p) {
    if (p==NULL) return;
    em_ordem(p->fesq);
    cout << p->valor << " ";
    em_ordem(p->fdir);
}

// Lista os elementos por Nivel
void arvore_bin::por_nivel() {
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
void arvore_bin::pre_ordem_nao_rec() {
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
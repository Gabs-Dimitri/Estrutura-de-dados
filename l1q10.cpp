#include <iostream>
#include <vector>

using namespace std;

struct node {
    int valor;
    node* pai;  // node pai
    node* fesq; // filho esquerdo
    node* fdir; // filho direito
};


// Lista os elementos em PRE-Ordem
void pre_ordem(node* p) {
    if (p==NULL) return;
    cout << p->valor << " ";
    pre_ordem(p->fesq);
    pre_ordem(p->fdir);
}

// Lista os elementos em POS-Ordem
void pos_ordem(node* p) {
    if (p==NULL) return;
    pos_ordem(p->fesq);
    pos_ordem(p->fdir);
    cout << p->valor << " ";
}

// Lista os elementos em EM-Ordem
void em_ordem(node* p) {
    if (p==NULL) return;
    em_ordem(p->fesq);
    cout << p->valor << " ";
    em_ordem(p->fdir);
}

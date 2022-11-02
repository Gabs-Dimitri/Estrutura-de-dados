#include <iostream>

using namespace std;

struct node {
    char valor;
    node* pai;
    node* esq;
    node* dir;
    int altura;// altura da subarvore com raiz no noh
    int tamanho;// tamanho da subarvore com raiz no noh

    node(char k) {//construtor
        pai=esq=dir=NULL;
        valor = k;
        tamanho=1;
    }
};

int altura(node* p) {
    if (p==NULL) return -1;
    return p->altura;
}

int tamanho(node* p) {
    if (p==NULL) return 0;
    return p->tamanho;
}

class tree_avl {
    node* raiz;
    void Rotacao_Direita(node* p);
};

void tree_avl::Rotacao_Direita(node* p) {
    node* q = p->esq;
    p->esq = q->dir;
    if (p->esq!=NULL) p->esq->pai = p;

    if (p->pai==NULL) raiz = q;
    else if (p==p->pai->esq)
        p->pai->esq = q;
    else
        p->pai->dir = q;

    q->pai = p->pai;
    q->dir = p;
    p->pai = q;

    p->altura  = 1 + max( altura(p->esq) ,  altura(p->dir) );
    q->altura  = 1 + max( altura(q->esq) ,  altura(q->dir) );
    p->tamanho = 1 +     tamanho(p->esq) + tamanho(p->dir);
    q->tamanho = 1 +     tamanho(q->esq) + tamanho(q->dir);
}
#include <iostream>
#include <ctime>

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

class tree_bs {
    node* raiz;
    void transplant(node* u, node* v);
    void inserir(char c);
    void atualizar_alt_tam(node* p);
    int ordem(node* p, char c);
    node* selecao(node* p, int k);
    node* minimo(node* p);
    node* maximo(node* p);
public:
    node* minimo();
    node* maximo();
    node* sucessor(node* p);    
    void inserir(string s);
    void remover(node* z);
    int ordem(char c);
    node* selecao(int k);
};

node* tree_bs::minimo() {
    if (raiz==NULL) return NULL;
    return minimo(raiz);
}

node* tree_bs::minimo(node* p) {
    while (p->esq != NULL) p = p->esq;
    return p;
}


node* tree_bs::sucessor(node* p) {
    if (p->dir!=NULL)
        return minimo(p->dir);

    node* pp = p->pai;
    while ((pp!=NULL) && (pp->esq!=p)) {
        p  = pp;
        pp = p->pai;
    }
    return pp;
}

void tree_bs::atualizar_alt_tam(node* p) {
    if (p==NULL) return;

    p->altura = 1 + max(altura(p->esq),altura(p->dir));
    p->tamanho = 1 + tamanho(p->esq) + tamanho(p->dir);

    atualizar_alt_tam(p->pai);
}

void tree_bs::inserir(string s) {
    for (int i=0; i<s.size(); i++)
        inserir(s[i]);
}

void tree_bs::inserir(char c) {
    node* z = new node(c);

    node* pp = NULL;
    node* p  = raiz;
    while (p!=NULL) {
        pp = p;
        if (z->valor < p->valor)
             p = p->esq;
        else p = p->dir;
    }
    z->pai = pp;
    if (pp==NULL) raiz = z;
    else if (z->valor < pp->valor)
         pp->esq = z;
    else 
        pp->dir = z;
    atualizar_alt_tam(z);
}

void tree_bs::remover(node* z) {
    if (z==NULL) return;
    if (z->esq==NULL) {
        transplant(z, z->dir);
    } else if (z->dir==NULL) {
        transplant(z, z->esq);
    } else {
        node* suc = sucessor(z);
        if (suc->pai!=z) {
            transplant(suc, suc->dir);
            suc->dir = z->dir;
            suc->dir->pai = suc;
        }
        suc->esq = z->esq;
        suc->esq->pai = suc;
        transplant(z, suc);
    }
    delete z;
}

void tree_bs::transplant(node* u, node* v) {
    if (u==NULL) return;
    if (u->pai==NULL) {
        raiz = v;
    } else if (u == u->pai->esq) {
        u->pai->esq = v;
    } else {
        u->pai->dir = v;
    }
    if (v!=NULL) v->pai = u->pai;



    if (v!=NULL) atualizar_alt_tam(v);
    else         atualizar_alt_tam(u->pai);
}

node* tree_bs::selecao(int k) {return selecao(raiz, k);}

node* tree_bs::selecao(node* p, int k) {
    if (p==NULL) return NULL;
    if ( k < 1 ) return NULL;
    if ( k >= p->tamanho) return maximo(p);

    if (k == tamanho(p->esq)+1) return p;
    if (k <= tamanho(p->esq))
        return selecao(p->esq, k);

    return selecao(p->dir, k-1 - tamanho(p->esq));
}



int tree_bs::ordem(char c) {return ordem(raiz, c);}

int tree_bs::ordem(node* p, char c) {
    if (p==NULL) return -INT64_MAX;

    if (c == p->valor) return tamanho(p->esq) + 1;
    if (c <  p->valor)
        return ordem(p->esq, c);

    return ordem(p->dir, c) + tamanho(p->esq) + 1;
}

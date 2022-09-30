#include <iostream>

using namespace std;

struct node {
    int valor;
    node* prox;
};

class lista_simples {
    node* inicio;
    node* fim;
public:
    void insere_no_inicio(int k);
    void insere_na_posicao_a_frente(node* p, int k);
    void insere_no_fim(int k);
    void apaga_noh_da_frente(node* p);
    void apaga_noh_primeiro();
    node* busca(int k);
    void imprime();
    bool vazia();
    void apaga_tudo();
    void inverte_lista();
    void push(int k);
    int pop();
    void enqueue(int k);
    int dequeue();
};

void lista_simples :: insere_no_inicio(int k){
    node* q = new node;
    q->valor = k;
    q->prox = inicio;
    inicio = q;
    if (fim==NULL) fim = q;
}

void lista_simples :: insere_na_posicao_a_frente(node* p, int k){
    if(p == NULL) return;
    node* q = new node;
    q->valor = k;
    q->prox = p->prox;
    p->prox = q;
    if(p==fim) fim = q;
}

void lista_simples :: insere_no_fim(int k){
    if(inicio == NULL)
        insere_no_inicio(k);
    else    
        insere_na_posicao_a_frente(fim, k);
}

void lista_simples :: apaga_noh_da_frente(node* p){
    if((p==NULL) || (p->prox == NULL)) return;
    node* q = p->prox;
    p->prox = p->prox->prox;
    delete q;
    if (q==fim) fim = p;
}

void lista_simples :: apaga_noh_primeiro(){
    if(inicio==NULL) return;
    node* q = inicio->prox;
    delete inicio;
    inicio = q;
    if(inicio == NULL) fim = NULL;
}

node* lista_simples :: busca(int k){
    node* p = inicio;
    while(p!=NULL){
        if(p->valor==k) return p;
        p = p->prox;
    }
    return NULL;
}

void lista_simples :: imprime(){
    node* p = inicio;
    while(p != NULL){
        cout << p->valor << " ";
        p = p->prox;
    }
    cout << "\n";
}

bool lista_simples :: vazia(){
    if(inicio == NULL) return true;
    return false;
}

void lista_simples :: apaga_tudo(){
    if(inicio == NULL) return;
    node* p = inicio;
    node* q = p->prox;
    while(p != NULL){
        delete p;
        p = q;
        if(p != NULL) q = p->prox;
    }
    inicio = NULL;
}

void lista_simples :: inverte_lista(){
    if((inicio == NULL) || (inicio->prox == NULL)) return;
    node* p = inicio;
    node* q = p->prox;
    node* r = p->prox->prox;
    inicio->prox = NULL;
    while(q != NULL){
        q->prox = p;
        p = q;
        q = r;
        if(r != NULL) r = r->prox;
    }
    inicio = p;
}

void lista_simples :: push(int k){
    insere_no_inicio(k);
}

int lista_simples :: pop(){
    if(vazia()) {
        return -1;
    }
    int k = inicio->valor;
    apaga_noh_primeiro();
    cout << k << " ";
    return k;
}

void lista_simples :: enqueue(int k){
    insere_no_fim(k);
}

int lista_simples :: dequeue(){
    if(vazia()) return -1;
    int k = inicio->valor;
    apaga_noh_primeiro();
    cout << k << " ";
    return k;
}
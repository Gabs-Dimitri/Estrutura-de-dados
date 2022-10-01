#include <iostream>

using namespace std;

struct node {
    int valor;
    node* prox;
    node* ant;
};

class lista_dupla {
    node* Nulo; //sentinela (indica o inicio e fim da lista)
public: 
    void insere_na_posicao_a_frente(node* p, int k);
    void insere_no_inicio(int k);
    void insere_no_fim(int k);
    void apaga_noh(node* p);
    void apaga_tudo();
    node* busca(int k);
    void imprime();
    bool vazia();
    void inverte_lista();
    void push(int k);
    int pop();
    void enqueue(int k);
    int dequeue();
};   

void lista_dupla :: insere_na_posicao_a_frente(node* p, int k){
    node* q = new node;
    q->valor = k;
    q->ant = p;
    q->prox = q->ant->prox;
    q->ant->prox = q;
    q->prox->ant = q;
}

void lista_dupla :: insere_no_inicio(int k){
    insere_na_posicao_a_frente(Nulo, k);
}

void lista_dupla :: insere_no_fim(int k){
    insere_na_posicao_a_frente(Nulo->ant, k);
}

void lista_dupla :: apaga_noh(node* p){
    if (p==Nulo) return;
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    delete p;
}

void lista_dupla :: apaga_tudo(){
    while(Nulo->prox != Nulo){
        apaga_noh(Nulo->prox);
    }
}

node* lista_dupla :: busca(int k){
    node* p = Nulo->prox;
    while (p!=Nulo){
        if(p->valor == k) return p;
        p = p->prox;
    }
    return Nulo;
}

void lista_dupla :: imprime(){
    node* p = Nulo->prox;
    while (p!=Nulo){
        cout << p->valor << " ";
        p = p->prox;
    }
    cout << "\n";
}

bool lista_dupla :: vazia(){
    if(Nulo->prox == Nulo)
        return true;
    return false;
}

void lista_dupla :: inverte_lista(){
    if(Nulo->prox == Nulo->ant) return;
    node* p = Nulo;
    do{
        node* q = p->prox;
        p->prox = p->ant;
        p->ant = q;
        p = q;
    } while (p!=Nulo);
}

void lista_dupla :: push(int k){
    insere_no_inicio(k);
}

int lista_dupla :: pop(){
    if(vazia()) return -1;
    int k = Nulo->prox->valor;
    apaga_noh(Nulo->prox);
    cout << k << " ";
    return k;
}

void lista_dupla :: enqueue(int k){
    insere_no_fim(k);
}

int lista_dupla :: dequeue(){
    if (vazia()) return -1;
    int k = Nulo->prox->valor;
    apaga_noh(Nulo->prox);
    cout << k << " ";
    return k;
}
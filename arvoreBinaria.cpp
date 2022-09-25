#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct node {
    int valor;
    node* pai;
    node* esq;
    node* dir;
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
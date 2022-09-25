#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
	int valor;
	struct node* prox;
	struct node* ant;
} node;

node* InverteLista(node* raiz) {
    node* noh = raiz;
    if (noh==NULL) return NULL;
    node* nooh = noh->prox;
    noh->prox = NULL;
    while (nooh!=NULL) {
        node* noooh = nooh->prox;
        nooh->prox = noh;
        noh = nooh;
        nooh = noooh;
    }
    return noh;
}
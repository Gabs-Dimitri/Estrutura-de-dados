#include <iostream>
#include <vector>

using namespace std; 

typedef struct node {
	int valor;
	struct node* prox;
	struct node* ant;
} node;

void print_ainda_vivos(node* Pri) {
    node* noh = Pri;
    do{ cout << noh->valor << " ";
        noh = noh->prox;
    } while (noh!=Pri);
}

#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

struct node {
	char valor;
	node* pai;      // pai
	node* filhoesq; // filho esquerdo
	node* irmaodir; // irmao direito
};

class arvore {
    node* raiz;
    node* sub_arvore(string &s, int &i);
public:
    arvore(string s); //construtor
    ~arvore();       //destrutor
};

node* arvore::sub_arvore(string &s, int &i) {
    while ((i<s.size()) && ((s[i]== '(') || (s[i]== ' ')) ) i++;
    if ((i>=s.size())||(s[i] == ')')) {
        i++;
        return NULL;
    }
    node* p = new node;
    p->valor = s[i++];

    node* q = sub_arvore(s,i);
    p->filhoesq = q;

    while(q != NULL) {
        q->pai = p;
        node* r = sub_arvore(s,i);
        q->irmaodir = r;
        q = r;
    }
    return p;
}
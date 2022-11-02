#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	char valor;
    node* pai;
    vector<node*> filho;
};

class arvore {
    node* raiz;
    node* sub_arvore(string &s, int &i);
public:
    arvore(string s); //construtor
    ~arvore();       //destrutor
};

node* arvore::sub_arvore(string &s, int &i){
    while ((i<s.size()) && ((s[i]== '(') || (s[i]== ' ')) ) i++;
    if ((i>=s.size())||(s[i] == ')')) {
        i++;
        return NULL;
    }
    node* p = new node;
    p->valor = s[i++];

    while(true) {
        node* q = NULL;
        q = sub_arvore(s,i);
        if (q== NULL) break;
        p->filho.push_back(q);
        q->pai = p;
    }
    return p;
}

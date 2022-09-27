#include <iostream>
#include <vector>

using namespace std;

class pilha {
    int* vet;
    int topo;
    int tam;
public:
    bool push(int x);
    int pop();
    bool vazia();
    bool cheia();
};

bool pilha :: push(int x){
    if(cheia()) 
        return false;
    vet[++topo] = x;
    return true;
}

int pilha :: pop(){
    if(vazia())
        return -1;
    return vet[topo--];
}

bool pilha :: vazia(){
    if(topo < 0)
        return true;
    return false;
}

bool pilha :: cheia(){
    if(topo >= tam-1)
        return true;
    return false;
}
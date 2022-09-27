#include <iostream>
#include <vector>

using namespace std;

class fila{
    int* vet;
    int ini;
    int fim;
    int tam;
public:
    bool enqueue(int x);
    int dequeue();
    bool vazia();
    bool cheia();
};

bool fila :: enqueue(int x){
    if(cheia())
        return false;
    vet[fim] = x;
    if(fim == tam-1)
        fim = 0;
    fim++;
    return true;
}

int fila :: dequeue(){
    if(vazia())
        return -1;
    int x = vet[ini];
    if(ini == tam-1)
        ini = 0;
    ini++;
    return x;
}

bool fila :: vazia(){
    if(ini == fim)
        return true;
    return false;
}

bool fila :: cheia(){
    if(ini == fim+1)
        return true;
    if((ini==0)&&(fim==tam-1))
        return true;
    return false;
}
#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>

using namespace std;

class Conjunto{
    vector<int> v;
    int busca_binaria(int x);
public:
    bool vazio();
    int tamanho();
    void imprime();
    void apaga_tudo();
    bool pertence(int valor);
    bool push(int valor);
    void uniao(Conjunto &C1, Conjunto &C2);
    void intersecao(Conjunto &C1, Conjunto &C2);
};

int Conjunto :: busca_binaria(int x){
    int p = 0;
    int r = v.size()-1;
    while(p <= r){
        int q = (p+r)/2;
        if(v[q] < x){
            p = q + 1;
        }else if(v[q] > x){
            r = q - 1;
        }else if(v[q] == x){
            return q;
        }
    }
    return -1;
}

bool Conjunto :: vazio(){
    if(v.size() == 0)
        return true;
    else    
        return false;
}

int Conjunto :: tamanho(){
    return v.size();
}

void Conjunto :: imprime(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void Conjunto :: apaga_tudo(){
    v.clear();
}

bool Conjunto :: pertence(int valor){
    if(busca_binaria(valor < 0))
        return false;
    return true;
}

bool Conjunto :: push(int valor){
    if(pertence(valor)){
        return false;
    }
    int i = v.size()-1;
    v.push_back(valor);
    while((i >= 0) && (v[i] > valor)){
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = valor;
    return true;    
}

void Conjunto :: uniao(Conjunto &C1, Conjunto &C2){
    apaga_tudo();
    int i, j;
    int n1 = C1.tamanho();
    int n2 = C2.tamanho();
    if(n1 == 0){
        for(j = 0; j < n2; j++){
            v.push_back(C2.v[i]);
        }
        return;
    }
    if(n2 == 0){
        for(i = 0; i < n1; i++){
            v.push_back(C1.v[i]);
        }
        return;
    }
    i = j = 0;
    int ultimo = min(C1.v[0], C2.v[0]);
    if(ultimo == C1.v[0]){
        i++;
    }else
        j++;
    v.push_back(ultimo);
    while((i < n1) || (j < n2)){
        if((j >= n2) || ((i < n1) && (C1.v[i] <= C2.v[j]))){
            if(C1.v[i] > ultimo){
                v.push_back(C1.v[i]);
                ultimo = C1.v[i];
            }
            i++;
        }else {
            if(C2.v[j] > ultimo){
                v.push_back(C2.v[j]);
                ultimo = C2.v[j];
            }
            j++;
        }
    }
}

void Conjunto :: intersecao(Conjunto &C1, Conjunto &C2){
    if(C1.tamanho() > C2.tamanho()){
        intersecao(C2, C1);
        return;
    }
    apaga_tudo();
    for(int i = 0; i < C1.tamanho(); i++){
        if(C2.pertence(C1.v[i]))
            v.push_back(C1.v[i]);
    }
}

int main(){
    Conjunto C;
    srand(time(NULL));
    for(int i = 0; i < 50; i++){
        int x = rand()%100;
        C.push(x);
    }
    cout << "Tamanho: " << C.tamanho();
    cout << "Valores ímpares: ";
    for(int i = 1; i < 100; i+2){
        if(C.pertence(i)){
            cout << i << " ";
        }
    }
}
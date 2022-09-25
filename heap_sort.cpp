#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>

using namespace std;

class Heap{
    vector<double> v;
    void min_heapify(int i);
public:
    bool vazio();
    void push(double valor);
    double extract_min();
};

void Heap :: min_heapify(int i){
    int m = i;
    int esq = 2*i + 1;
    int dir = esq + 1;
    int n = v.size();
    if((esq < n) && (v[esq] < v[m]))
        m = esq;
    if((dir < n) && (v[dir] < v[m]))
        m = dir;
    if(m != i){
        double z = v[i];
        v[i] = v[m];
        v[m] = z;
        min_heapify(m);
    }
}

bool Heap :: vazio(){
    if(v.size() == 0){
        return true;
    }else   
        return false;
}

void Heap :: push(double valor){
    v.push_back(valor);
    int i = v.size()-1;
    int pai = floor((i-1)/2.0);
    while((pai >= 0) && (v[pai] > v[i])){
        double z = v[i];
        v[i] = v[pai];
        v[pai] = z;
        i = pai;
        pai = floor((pai - 1)/2.0);
    }
}

double Heap :: extract_min(){
    if(vazio())
        return -1;
    double minimo = v[0];
    int n = v.size();
    v[0] = v[n-1];
    v.pop_back();
    min_heapify(0);
    return minimo;
}

int main(){
    vector<double> v;
    srand(time(NULL));
    for(int i = 0; i < 50; i++){
        v.push_back((double) rand()/RAND_MAX);
    }
    Heap H;
    for(int i = 0; i < 50; i++){
        H.push(v[i]);
    }
    while(!H.vazio()){
        cout << H.extract_min() << " ";
    }
}
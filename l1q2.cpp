#include <iostream>
#include <vector>

using namespace std;

int questao2(int* v, int N, int x){
    int p, q, r;
    p = 1;
    r = (N+1)/2;
    while(p <= r){
        int q = (p+r)/2;
        if(v[2*q-1] < x) 
            p = q+1;
        else if(v[2*q-1] > x)
            r = q-1;
        else    
            return 2*q-1;
    }
    p = 1;
    r = N/2;
    while(p <= r){
        int q = (p+r)/2;
        if(v[2*q] < x)
            r = q-1;
        else if(v[2*q] > x)
            p = q+1;
        else    
            return 2*q;
    }
}
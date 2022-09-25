#include <iostream>
#include <vector>
 
using namespace std;
 
void Jose(vector<int> N, int k, int i)
{
    if (N.size() == 1) {
        cout << N[0] << endl;
        return;
    }
    i = ((i + k) % N.size());
    N.erase(N.begin() + i);
    Jose(N, k, i);
}
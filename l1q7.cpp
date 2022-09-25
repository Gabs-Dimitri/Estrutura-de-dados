#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string expr_to_polonesa(string expr, bool rev) {
    stack<string> Pilha;
    stack<string> Pilha_op;
    int i = 0;
    while (true) {
        char c = expr[i++];
        if (c==0) break;
        string s(1,c);
        if ((c=='+')||(c=='-')||(c=='*')||(c=='/')) {
            Pilha_op.push(s);
        } else
        if (c==')') {
            string B = Pilha.top(); Pilha.pop();
            string A = Pilha.top(); Pilha.pop();
            string op = Pilha_op.top(); Pilha_op.pop();
            if ((A=="")||(B=="")||(op=="")) return "";

            string aux;
            if (rev) aux = A+B+op;
            else aux = op+A+B;
            Pilha.push(aux);
        } else if ((c!='(')&&(c!=' ')) {
            Pilha.push(s);
        }
    }
    return Pilha.top();
}


string polonesa_to_expr(string expr, bool rev) {
    int i;
    int N = expr.size();
    stack<string> Pilha;
    if (rev) i=0; else i=N-1;
    while (true) {
        if ((i<0)||(i>=N)) break;
        char c = expr[i];
        string s(1,c);
        if (rev) i++; else i--;
        if ((c=='+')||(c=='-')||(c=='*')||(c=='/')) {
            string B = Pilha.top(); Pilha.pop();
            string A = Pilha.top(); Pilha.pop();
            if ((A=="")||(B=="")) return "";

            string aux;
            if (rev) aux = "("+A+c+B+")";
            else aux = "("+B+c+A+")";
            Pilha.push(aux);
        } else
        if (c!=' ') {
            Pilha.push(s);
        }
    }
    return Pilha.top();
}
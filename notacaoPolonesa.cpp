#include <iostream>
#include <stack>
#include <string>

using namespace std;

string expr_to_polonesa(string expr, bool rev);
string polonesa_to_expr(string expr, bool rev);

string expr_to_polonesa(string expr, bool rev) {
    stack<string> P1, P2;
    int i = 0;
    while(true){
        char c = expr[i++];
        if (c==0) break;
        string s(1,c);
        if((c=='+') || (c=='-') || (c=='*') || (c=='/')){
            P2.push(s);
        } else
        if(c==')'){
            string B = P1.top(); P1.pop();
            string A = P1.top(); P1.pop();
            string op = P2.top(); P2.pop();
            if((A=="") || (B=="") || (op=="")) return "";
            string aux;
            if(rev) aux = A+B+op;
            else aux = op+A+B;
            P1.push(aux);
        } else if((c!='(')&&(c!=' ')){
            P1.push(s);
        }
    }
    string s = P1.top(); P1.pop();
    return s;
}

string polonesa_to_expr(string expr, bool rev) {
    int i;
    int N = expr.size();
    stack<string> P;
    if (rev) i=0; else i=N-1;
    while (true) {
        if ((i<0)||(i>=N)) break;
        char c = expr[i];
        string s(1,c);
        if (rev) i++; else i--;
        if ((c=='+')||(c=='-')||(c=='*')||(c=='/')) {
            string B = P.top(); P.pop();
            string A = P.top(); P.pop();
            if ((A=="")||(B=="")) return "";

            string aux;
            if (rev) aux = "("+A+c+B+")";
            else aux = "("+B+c+A+")";
            P.push(aux);
        } else
        if (c!=' ') {
            P.push(s);
        }
    }
    string s = P.top(); P.pop();
    return s;
}
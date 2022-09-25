#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <climits>
#include <stack>
#include <windows.h>
using namespace std;


// QUESTOES (algoritmos principais)
void Questao2(int N);
void Questao3(int N);
void Questao4(int N);
void Questao5(int N);
void Questao6(int N);
void Questao7();
void Questao8(int N);
void Questao9(int N, int k);




// -------------------------------------------------------------
// --- MAIN ----------------------------------------------------
// -------------------------------------------------------------
int main() {
	int i;

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 2 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao2(20); //par
	Questao2(21); //impar

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 3 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao3(50);

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 4 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao4(50);

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 5 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao5(50);

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 6 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao6(50);

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 7 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao7();

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 8 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao8(50);

	cout<<"-------------------------------------------------------------\n";
	cout<<"---------------- QUESTAO 9 ----------------------------------\n";
	cout<<"-------------------------------------------------------------\n";

	Questao9(2,2);
	Questao9(3,2);
	Questao9(4,2);
	Questao9(5,2);
	Questao9(6,2);
	Questao9(50,5);

	return 0;
}




// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 2 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void trocar(int& x, int& y) {int z = x; x = y; y = z;}

int Questao2busca(int* vetor, int elemento, int N) {
    int p,q,r;

    // Procura nas posicoes impares
    p=1; r=(N+1)/2;
    while (p<=r) {
        int q = (p+r)/2;
        if (vetor[2*q-1]< elemento) p = q+1; else
        if (vetor[2*q-1]> elemento) r = q-1; else
        if (vetor[2*q-1]==elemento) return 2*q-1;
    }
    // Procura nas posicoes pares
    p=1; r=N/2;
    while (p<=r) {
        int q = (p+r)/2;
        if (vetor[2*q]> elemento) p = q+1; else
        if (vetor[2*q]< elemento) r = q-1; else
        if (vetor[2*q]==elemento) return 2*q;
    }
    return -1;
}

void Questao2(int N) {
	int* vetor = new int [N+1];
	for (int i=1; i<=N; i+=2) vetor[i] = i;
	for (int i=2; i<=N; i+=2) vetor[i] = N-i+2 -N%2;
	cout<<"Vetor[1..."<<N<<"] = (";
	for (int i=1; i<=N; i++) cout<<vetor[i]<<" ";
	cout<<")\n\n";

	int elemento = 7;
	int q = Questao2busca(vetor, elemento, N);
	if (q<0) cout<<"Elemento "<<elemento<<" nao encontrado\n";
	else cout<<"Elemento "<<elemento<<" encontrado na posicao "<<q<<"\n";

	elemento = 14;
	q = Questao2busca(vetor, elemento, N);
	if (q<0) cout<<"Elemento "<<elemento<<" nao encontrado\n";
	else cout<<"Elemento "<<elemento<<" encontrado na posicao "<<q<<"\n";

	elemento = 21;
	q = Questao2busca(vetor, elemento, N);
	if (q<0) cout<<"Elemento "<<elemento<<" nao encontrado\n\n";
	else cout<<"Elemento "<<elemento<<" encontrado na posicao "<<q<<"\n\n";

	delete[] vetor;
}

// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 3 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void maxheapify(int* vetor, int i, int p, int r) {
    int m = i;
    int esq = p+2*(i-p)+1;
    int dir = p+2*(i-p)+2;
    if ((esq<=r)&&(vetor[esq]>vetor[i])) m = esq;
    if ((dir<=r)&&(vetor[dir]>vetor[m])) m = dir;
    if (m != i) {
        trocar(vetor[i], vetor[m]);
        maxheapify(vetor,m,p,r);
    }
}
void HeapSort(int* vetor, int p, int r) {
    int i;
    for (i=(r+p-1)/2; i>=p; i--) {
        maxheapify(vetor,i,p,r);
    }
    for (i=r;i>p;i--) {
        trocar(vetor[p], vetor[i]);
        r = r-1;
        maxheapify(vetor,p,p,r);
    }
}

void Questao3(int N) {
	int* vetor = new int [N];
	srand(time(NULL));
	cout<<"Vetor original: ";
	for (int i = 0; i<N; i++) {
        vetor[i] = rand() % 1000;
        cout<<vetor[i]<<" ";
	}
	cout<<"\n\n";
	cout<<"Vetor ord parcial: ";

	HeapSort(vetor,N/3,2*N/3);
	for (int i = 0; i<N; i++) cout<<vetor[i]<<" ";
	cout<<"\n\n";
	delete[] vetor;
}

// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 4 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// Usa heap mínimo enraizado na última posição do vetor
// Considerando o vetor da posição p até a posição r
void min_heapify(int* vetor, int i, int p, int r) {
    int m = i;
    int esq = 2*i-r-1;
    int dir = esq-1;
    if ((esq>=p)&&(vetor[esq]<vetor[i])) m = esq;
    if ((dir>=p)&&(vetor[dir]<vetor[m])) m = dir;
    if (m != i) {
        trocar(vetor[i], vetor[m]);
        min_heapify(vetor,m,p,r);
    }
}

void HeapSort_min(int* vetor, int p, int r) {
    int i;
    for (i=(r+p+2)/2; i<=r; i++) {
        min_heapify(vetor,i,p,r);
    }
    for (i=p;i<r;i++) {
        trocar(vetor[r], vetor[i]);
        p = p+1;
        min_heapify(vetor,r,p,r);
    }
}

void Questao4(int N) {
	int* vetor = new int [N];
	srand(time(NULL));
	cout<<"Vetor original: ";
	for (int i = 0; i<N; i++) {
        vetor[i] = rand() % 1000;
        cout<<vetor[i]<<" ";
	}
	cout<<"\n\n";
	cout<<"Vetor ordenado: ";
	HeapSort_min(vetor,0,N-1);
	for (int i = 0; i<N; i++) cout<<vetor[i]<<" ";
	cout<<"\n\n";
	delete[] vetor;
}

// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 5 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
typedef struct node {
	int valor;
	struct node* prox;
	struct node* ant;
} node;

node* InverteLista(node* raiz) {
    node* noh = raiz;
    if (noh==NULL) return NULL;
    node* nooh = noh->prox;
    noh->prox = NULL;
    while (nooh!=NULL) {
        node* noooh = nooh->prox;
        nooh->prox = noh;
        noh = nooh;
        nooh = noooh;
    }
    return noh;
}

void Questao5(int N) {
    cout<<"Lista simples: ";
    node* raiz = new node;
    node* noh = raiz;
    noh->valor = 1;
    for (int i=2; i<=N; i++) {
        noh->prox = new node;
        noh = noh->prox;
        noh->valor = i;
    }
    noh->prox = NULL;

    noh = raiz;
    while (noh!=NULL) {
        cout<<noh->valor<<" ";
        noh = noh->prox;
    }

    cout<<"\n\nLista invertida: ";
    raiz = InverteLista(raiz);
    noh = raiz;
    while (noh!=NULL) {
        cout<<noh->valor<<" ";
        node* aux = noh;
        noh = noh->prox;
        delete aux;
    }
    cout<<"\n\n";
}


// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 6 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------

typedef struct pilhadupla {
    int* vet;//pilha de inteiros
    int topo1, topo2;// pilha topo
    int tam;// pilha tamanho
} pilha;

bool pilha1_vazia(pilhadupla& P) {
    if (P.topo1<=0) return true;
    return false;
}

bool pilha2_vazia(pilhadupla& P) {
    if (P.topo2>P.tam) return true;
    return false;
}

bool pilha_cheia(pilha& P) {
    if (P.topo1+1>=P.topo2) return true;
    return false;
}

bool Push_1(pilhadupla& P, int x) {
    if (pilha_cheia(P)) return false;
    P.vet[++P.topo1] = x;
    return true;
}

int Pop_1(pilhadupla& P) {
    if (pilha1_vazia(P)) {
        cout << "Pilha Vazia (estouro negativo)" << endl;
        return -1;
    }
    return P.vet[P.topo1--];
}

bool Push_2(pilhadupla& P, int x) {
    if (pilha_cheia(P)) return false;
    P.vet[--P.topo2] = x;
    return true;
}

int Pop_2(pilhadupla& P) {
    if (pilha2_vazia(P)) {
        cout << "Pilha Vazia (estouro negativo)" << endl;
        return -1;
    }
    return P.vet[P.topo2++];
}

void pilha_create(pilhadupla& P, int N) {
    P.vet = NULL;
    P.tam = 0;
    P.topo1 = 0;
    P.topo2 = N+1;
    if (N<=0) return;
    P.tam = N;
    P.vet = new int [N+1];
}

void pilha_delete(pilhadupla& P) {
    if (P.vet==NULL) return;
    delete [] P.vet;
    P.vet = NULL;
    P.tam = 0;
    P.topo1 = 0;
    P.topo2 = P.tam+1;
}

void Questao6(int N) {
    pilhadupla P;

    pilha_create(P,20);
    cout <<"Pilhas preenchidas aleatoriamente com PUSH_1 ou PUSH_2\n";
    int k=1;
    while (!pilha_cheia(P)) {
        if (rand()%2==0)
             Push_1(P,k++);
        else Push_2(P,k++);
    }
    cout << endl;
    cout <<"Numeros do vetor da pilha dupla: ";
    for (k=1; k<=P.tam; k++) cout << P.vet[k] << " ";

    cout<<"\n\n";
    cout <<"Numeros tirados da PILHA_1 com POP_1: ";
    while (!pilha1_vazia(P)) cout << Pop_1(P) << " ";
    cout<<"\n\n";
    cout <<"Numeros tirados da PILHA_2 com POP_2: ";
    while (!pilha2_vazia(P)) cout << Pop_2(P) << " ";
    cout<<"\n\n";
    pilha_delete(P);
}


// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 7 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
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


void Questao7() {
    cout<<"expr: ((A*B)-(C/D)) => polo_rev: "<<expr_to_polonesa("((A*B)-(C/D))",1)<<endl;
    cout<<"expr: ((A*B)-(C/D)) => polonesa: "<<expr_to_polonesa("((A*B)-(C/D))",0)<<endl;
    cout<<"polo-rev: AB*CD/-   => expr: "<<polonesa_to_expr("AB*CD/-",1)<<endl;
    cout<<"polonesa: -*AB/CD   => expr: "<<polonesa_to_expr("-*AB/CD",0)<<endl;
    cout<<endl;
    cout<<"expr: (W+(X*(Y-Z))) => polo_rev: "<<expr_to_polonesa("(W+(X*(Y-Z)))",1)<<endl;
    cout<<"expr: (W+(X*(Y-Z))) => polonesa: "<<expr_to_polonesa("(W+(X*(Y-Z)))",0)<<endl;
    cout<<"polo-rev: WXYZ-*+   => expr: "<<polonesa_to_expr("WXYZ-*+",1)<<endl;
    cout<<"polonesa: +W*X-YZ   => expr: "<<polonesa_to_expr("+W*X-YZ",0)<<endl;
    cout<<endl;
    cout<<"expr: (((R+S)*T)-U) => polo_rev: "<<expr_to_polonesa("(((R+S)*T)-U)",1)<<endl;
    cout<<"expr: (((R+S)*T)-U) => polonesa: "<<expr_to_polonesa("(((R+S)*T)-U)",0)<<endl;
    cout<<"polo-rev: RS+T*U-   => expr: "<<polonesa_to_expr("RS+T*U-",1)<<endl;
    cout<<"polonesa: -*+RSTU   => expr: "<<polonesa_to_expr("-*+RSTU",0)<<endl;
    cout<<"\n";
}

// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 8 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
typedef struct deque_1 {
    int* vet;
    int ini, fim;// pilha topo
    int num, tam;// numero de elementos e tamanho maximo
} deque_1;

void Push(deque_1& D, int x, bool bfim) {
    if (D.num==D.tam) {cout<<"Deque_1 cheio\n"; return;}
    D.num++;
    if (bfim) {
        D.fim++; if (D.fim>D.tam) D.fim=1;
        D.vet[D.fim] = x;
    } else {
        D.ini--; if(D.ini<=0) D.ini=D.tam;
        D.vet[D.ini] = x;
    }
}
int Pop(deque_1& D, bool bfim) {
    if (D.num<=0) {cout<<"Deque_1 vazio"; return -1;}
    D.num--;
    int x;
    if (bfim) {
        x = D.vet[D.fim];
        D.fim--; if(D.fim<=0) D.fim=D.tam;
    } else {
        x = D.vet[D.ini];
        D.ini++; if(D.ini>D.tam) D.ini=1;
    }
    return x;
}
void Create(deque_1& D, int N) {
    D.vet = new int[N+1];
    D.ini = 1; D.fim = N;
    D.tam = N; D.num = 0;
}
void Delete(deque_1& D) {
    if (D.vet!=NULL) delete[] D.vet;
}



typedef struct deque_2 {
    node* inicio;// primeiro noh do deque (lista circular)
} deque_2;

void Push(deque_2& D, int x, bool bfim) {
    node* noh = new node;
    noh->valor = x;

    if (D.inicio==NULL) {
        D.inicio = noh;
        noh->ant = noh;
        noh->prox = noh;
    } else {
        noh->prox = D.inicio;
        noh->ant = D.inicio->ant;
        noh->prox->ant = noh;
        noh->ant->prox = noh;
    }
    if (!bfim) D.inicio = noh;
}

int Pop(deque_2& D, bool bfim) {
    if (D.inicio==NULL) {cout<<"Deque_2 vazio"; return -1;}
    node* noh = D.inicio;// noh que sera removido
    if (bfim) noh = noh->ant;
    else D.inicio = noh->prox;
    noh->ant->prox = noh->prox;
    noh->prox->ant = noh->ant;
    int x = noh->valor;
    if (D.inicio==noh) D.inicio = NULL;
    delete noh;
    return x;
}

void Questao8(int N) {
    int x;
    deque_1 D1;
    Create(D1,N);

    cout <<"\n Deque_1 - usando vetor";
    cout <<"\n Deque_1 PUSH fim POP fim: ";
    for (int i=1; i<=N; i++) Push(D1, i, true);
    while (D1.num>0) {x = Pop(D1,true); cout<<x<<" ";}

    cout <<"\n Deque_1 PUSH fim POP ini: ";
    for (int i=1; i<=N; i++) Push(D1, i, true);
    while (D1.num>0) {x = Pop(D1,false); cout<<x<<" ";}

    cout <<"\n Deque_1 PUSH ini POP fim: ";
    for (int i=1; i<=N; i++) Push(D1, i, false);
    while (D1.num>0) {x = Pop(D1,true); cout<<x<<" ";}

    cout <<"\n Deque_1 PUSH ini POP ini: ";
    for (int i=1; i<=N; i++) Push(D1, i, false);
    while (D1.num>0) {x = Pop(D1,false); cout<<x<<" ";}

    cout<<"\n\n\n";
    Delete(D1);

    deque_2 D2;
    D2.inicio = NULL;

    cout <<"\n Deque_2 - sem usar vetor";
    cout <<"\n Deque_2 PUSH fim POP fim: ";
    for (int i=1; i<=N; i++) Push(D2, i, true);
    while (D2.inicio!=NULL) {x = Pop(D2,true); cout<<x<<" ";}

    cout <<"\n Deque_2 PUSH fim POP ini: ";
    for (int i=1; i<=N; i++) Push(D2, i, true);
    while (D2.inicio!=NULL) {x = Pop(D2,false); cout<<x<<" ";}

    cout <<"\n Deque_2 PUSH ini POP fim: ";
    for (int i=1; i<=N; i++) Push(D2, i, false);
    while (D2.inicio!=NULL) {x = Pop(D2,true); cout<<x<<" ";}

    cout <<"\n Deque_2 PUSH ini POP ini: ";
    for (int i=1; i<=N; i++) Push(D2, i, false);
    while (D2.inicio!=NULL) {x = Pop(D2,false); cout<<x<<" ";}

    cout<<"\n\n\n";
}

// ------------------------------------------------------------------------------------------------
// ----- QUESTAO 9 --------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void print_ainda_vivos(node* Pri) {
    node* noh = Pri;
    do{ cout << noh->valor << " ";
        noh = noh->prox;
    } while (noh!=Pri);
}


void Questao9(int N, int k) {
    node* Pri;// primeiro noh da lista circular

    node* noh = new node;
    noh->valor = 1;
    Pri = noh;
    for (int i=2; i<=N; i++) {
        node* nooh = new node;
        nooh->valor = i;
        noh->prox = nooh;
        noh = nooh;
    }
    noh->prox = Pri;

    cout <<"Lista circular (N="<<N<<",k="<<k<<"):";
     cout<<endl; print_ainda_vivos(Pri);

    noh = Pri;
    for (int i=1; i<=N-k+1; i++) {
        for (int j=1; j<k-1; j++) noh = noh->prox;
        node* nooh = noh->prox->prox;
        if (noh->prox==Pri) Pri = nooh;
        delete noh->prox;
        noh->prox = nooh;
        noh = noh->prox;
        cout<<endl; print_ainda_vivos(Pri);
    }
    cout <<"            <--------   Sobreviventes\n";

    noh = Pri->prox;
    while (noh!=Pri) {
        node* nooh = noh->prox;
        delete noh;
        noh = nooh;
    }
    delete Pri;
    cout<<"\n\n";
}
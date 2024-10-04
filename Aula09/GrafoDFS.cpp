#include <bits/stdc++.h>
using namespace std;

struct No {
  int valorNo;
  bool bidirecional;

  No* proximo_no;
  No* no_anterior;

  No* no_filho;
};

No* InserirNo(No* raiz, int valor, int ponto_insercao, bool bidirecional) {
  if(raiz == NULL) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valorNo = valor;
    novo_no->bidirecional = false;
    novo_no->no_anterior = NULL;

    novo_no->proximo_no = NULL;
    novo_no->no_filho = NULL;

    return novo_no;
  }

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    if(percorre_grafo->valorNo == ponto_insercao) {
      No* novo_no = (No*)malloc(sizeof(No));
      novo_no->valorNo = valor;
      novo_no->bidirecional = bidirecional;
      novo_no->no_anterior = percorre_grafo;

      novo_no->proximo_no = percorre_grafo->no_filho;
      novo_no->no_filho = NULL;

      percorre_grafo->no_filho = novo_no;

      return raiz;
    }

    if(percorre_grafo->no_filho) {
      percorre_grafo->no_filho = InserirNo(percorre_grafo->no_filho, valor, ponto_insercao, bidirecional);
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }

  return raiz;
}

bool BuscarNo(No* raiz, int valor) {
  if(raiz == NULL) return false;

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    if(percorre_grafo->valorNo == valor) return true;

    if(BuscarNo(percorre_grafo->no_filho, valor)) return true;

    percorre_grafo = percorre_grafo->proximo_no;
  }

  return false;
}

void ImprimirGrafo(No* raiz) {
  if(raiz == NULL) return;

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    cout << percorre_grafo->valorNo << " ";
    
    if(percorre_grafo->no_filho) {
      ImprimirGrafo(percorre_grafo->no_filho);
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }
}

int main() {
  No* raiz = NULL;

  while (true) {
    int op;
    cin >> op;

    if(op == 1) {
      int valor, ponto_insercao;
      bool bidirecional;

      cin >> valor >> ponto_insercao >> bidirecional;

      raiz = InserirNo(raiz, valor, ponto_insercao, bidirecional);
      cout << endl;
    } else if(op == 2) {
      int valor;
      cin >> valor;

      cout << BuscarNo(raiz, valor) << endl;
      cout << endl;
    } else if(op == 3) {
      ImprimirGrafo(raiz);
      cout << endl;
    }
  }

  return 0;
}

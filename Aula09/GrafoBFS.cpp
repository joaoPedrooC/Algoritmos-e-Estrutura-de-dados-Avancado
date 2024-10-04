#include <bits/stdc++.h>
using namespace std;

struct No {
  int valor_no;
  bool bidirecional;

  No* proximo_no;
  No* no_anterior;

  No* vizinho;
};

No* InserirNo(No* raiz, int valor, int ponto_insercao, bool bidirecional) {
  if(raiz == NULL) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor_no = valor;
    novo_no->bidirecional = bidirecional;

    novo_no->no_anterior = NULL;
    novo_no->proximo_no = NULL;
    novo_no->vizinho = NULL;

    return novo_no;
  }

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    if(percorre_grafo->valor_no == ponto_insercao) {
      No* novo_no = (No*)malloc(sizeof(No));
      novo_no->valor_no = valor;
      novo_no->bidirecional = bidirecional;

      novo_no->no_anterior = percorre_grafo;
      novo_no->proximo_no = percorre_grafo->vizinho;
      novo_no->vizinho = NULL;

      percorre_grafo->vizinho = novo_no;

      return raiz;
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }

  percorre_grafo = raiz;

  while(percorre_grafo != NULL) {
    if(percorre_grafo->vizinho) {
      percorre_grafo->vizinho = InserirNo(percorre_grafo->vizinho, valor, ponto_insercao, bidirecional);
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }

  return raiz;
}

bool BuscarNo(No* raiz, int valor) {
  if(raiz == NULL) return false;

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    if(percorre_grafo->valor_no == valor) return true;

    percorre_grafo = percorre_grafo->proximo_no;
  }

  percorre_grafo = raiz;

  while(percorre_grafo != NULL) {
    if(percorre_grafo->vizinho) {
      if(BuscarNo(percorre_grafo->vizinho, valor)) return true;
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }

  return false;
}

void ImprimirGrafo(No* raiz) {
  No* percorre_grafo = raiz;
  
  while(percorre_grafo != NULL) {
    cout << percorre_grafo->valor_no << " ";
    
    percorre_grafo = percorre_grafo->proximo_no;
  }

  percorre_grafo = raiz;
  
  while(percorre_grafo != NULL) {
    if(percorre_grafo->vizinho) {
      ImprimirGrafo(percorre_grafo->vizinho);
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
#include <bits/stdc++.h>
using namespace std;

#define VISITADO 1
#define NAO_ENCONTRADO 0

struct No {
  int valor_no;
  bool bidirecional;
  bool estado;

  No* proximo_no;
  No* no_anterior;

  No* vizinho;
};

No* LimparVisitados(No* raiz) {
  if(raiz == NULL) return NULL;

  raiz->estado = NAO_ENCONTRADO;

  No* percorre_grafo = raiz;
  while(percorre_grafo != NULL) {
    percorre_grafo->estado = NAO_ENCONTRADO;

    percorre_grafo->vizinho = LimparVisitados(percorre_grafo->vizinho);

    percorre_grafo = percorre_grafo->proximo_no;
  }

  return raiz;
}

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
    if(percorre_grafo->estado != VISITADO) {
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

      percorre_grafo->estado = VISITADO;
    }

    percorre_grafo = percorre_grafo->proximo_no;
  }

  if(raiz->estado == VISITADO) raiz = LimparVisitados(raiz);
  percorre_grafo = raiz;

  while(percorre_grafo != NULL) {
    if(percorre_grafo->vizinho && percorre_grafo->estado != VISITADO) {
      percorre_grafo->vizinho = InserirNo(percorre_grafo->vizinho, valor, ponto_insercao, bidirecional);
    }

    percorre_grafo->estado = VISITADO;
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
    if(percorre_grafo->vizinho && percorre_grafo->estado != VISITADO) {
      if(BuscarNo(percorre_grafo->vizinho, valor)) return true;
    }

    percorre_grafo->estado = VISITADO;
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
    if(percorre_grafo->vizinho && percorre_grafo->estado != VISITADO) {
      ImprimirGrafo(percorre_grafo->vizinho);
    }

    percorre_grafo->estado = VISITADO;
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
      if(raiz->estado == VISITADO) raiz = LimparVisitados(raiz);
      cout << endl;
    } else if(op == 2) {
      int valor;
      cin >> valor;

      cout << BuscarNo(raiz, valor) << endl;
      cout << endl;

      raiz = LimparVisitados(raiz);
    } else if(op == 3) {
      ImprimirGrafo(raiz);
      raiz = LimparVisitados(raiz);
      cout << endl;
    }
  }

  return 0;
}
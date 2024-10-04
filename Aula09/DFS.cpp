#include <bits/stdc++.h>
using namespace std;

#define VISITADO 1
#define ENCONTRADO 0

struct vertice;

struct adjacencia {
  vertice* v;
  bool bidirecional;

  adjacencia* prox;
};

struct vertice {
  int valorVertice;

  adjacencia* cab;
};

struct grafo {
  vertice* adj;
};

bool PercorreVertice(vertice* v, int ponto_insercao, int valor, bool bidirecional) {
  if(v->valorVertice == valor) {
    vertice* novo_v = (vertice*)malloc(sizeof(vertice));
    novo_v->valorVertice = valor;
    novo_v->cab = NULL;
    
    adjacencia* a = (adjacencia*)malloc(sizeof(adjacencia));
    a->v = novo_v;
    a->bidirecional = bidirecional;
    a->prox = v->cab;

    v->cab = a;
    return true;
  }

  adjacencia* percorre_grafo = v->cab;
  while(percorre_grafo != NULL) {
    if(PercorreVertice(percorre_grafo->v, ponto_insercao, valor, bidirecional)) return true;
    percorre_grafo = percorre_grafo->prox;
  }

  false;
}

bool InserirAresta(grafo* g, int ponto_insercao, int valor, bool bidirecional) {
  if(g->adj == NULL) {
    vertice* v = (vertice*)malloc(sizeof(vertice));
    v->valorVertice = valor;
    v->cab = NULL;
    g->adj = v;

    return true;
  }

  vertice* percorre_grafo = g->adj;
  while(percorre_grafo != NULL) {
    if(percorre_grafo->valorVertice == valor) {
      vertice* v = (vertice*)malloc(sizeof(vertice));
      v->valorVertice = valor;
      v->cab = NULL;
      
      adjacencia* a = (adjacencia*)malloc(sizeof(adjacencia));
      a->v = v;
      a->bidirecional = bidirecional;
      a->prox = percorre_grafo->cab;

      percorre_grafo->cab = a;
      return true;
    }

    if(PercorreVertice(percorre_grafo->cab->v, ponto_insercao, valor, bidirecional)) return true;

    // percorre_grafo = percorre_grafo->cab->prox;
  }

  false;
}

grafo* CriaGrafo() {
  grafo* gr = (grafo*)malloc(sizeof(grafo));
  gr->adj = NULL;

  return gr;
}

int main() {
  grafo* g = CriaGrafo();

  while(true) {
    int ponto_insercao, valor;
    
    cout << "Ponto de insercao e valor para inserir: ";
    cin >> ponto_insercao >> valor;


  }
}
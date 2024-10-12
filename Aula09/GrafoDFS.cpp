#include <bits/stdc++.h>
using namespace std;

int quantidadeVertices = 0;

struct adjacencia {
  int valorAdj;
  int pesoAdj;

  adjacencia* proxima_adj;
};

struct vertice {
  int valor;
  adjacencia* listaAdjacencia;
};

vertice** InserirVertice(vertice** g, int valorVertice, int valorAdjacencia, int pesoAdjacencia) {
  adjacencia* novaAdjacencia = (adjacencia*)malloc(sizeof(adjacencia));
  novaAdjacencia->valorAdj = valorAdjacencia;
  novaAdjacencia->pesoAdj = pesoAdjacencia;
  novaAdjacencia->proxima_adj = NULL;

  if(g == NULL) {
    vertice** novoG = (vertice**)malloc(sizeof(vertice*));
    vertice* novoVertice = (vertice*)malloc(sizeof(vertice));

    novoVertice->valor = valorVertice;
    novoVertice->listaAdjacencia = novaAdjacencia;

    novoG[0] = novoVertice;
    quantidadeVertices++;

    return novoG;
  }
  
  vertice* insercao = NULL;
  for(int i = 0; i < quantidadeVertices && g[i] != NULL; i++) {
    if(g[i]->valor == valorVertice) {
      insercao = g[i];
      break;
    }
  }

  if(insercao) {
    novaAdjacencia->proxima_adj = insercao->listaAdjacencia;
    insercao->listaAdjacencia = novaAdjacencia;

    return g;
  }

  vertice* novoVertice = (vertice*)malloc(sizeof(vertice));

  novoVertice->valor = valorVertice;
  novoVertice->listaAdjacencia = novaAdjacencia;
  quantidadeVertices++;
  return g;
}

bool DFS(vertice** g, vertice* verticeInicial, int valorBusca, bool* visitados) {
  if(!verticeInicial) return false;
  if(verticeInicial->valor == valorBusca) return true;

  int indiceVertice;
  for(int i = 0; i < quantidadeVertices; i++) {
    if(g[i]->valor == verticeInicial->valor) {
      indiceVertice = i;
      break;
    }
  }

  adjacencia* percorre_adj = verticeInicial->listaAdjacencia;
  while(percorre_adj != NULL) {
    if(percorre_adj->valorAdj == valorBusca) return true;
    
    for(int i = 0; i < quantidadeVertices; i++) {
      if(g[i]->valor == percorre_adj->valorAdj && !visitados[i]) {
        if(DFS(g, g[i], valorBusca, visitados)) return true;
      }
    }

    visitados[indiceVertice] = true;
    percorre_adj = percorre_adj->proxima_adj;
  }

  return false;
}

bool BuscaProfundidade(vertice** g, int valorBusca) {
  bool* visitados = (bool*)calloc(sizeof(bool) * quantidadeVertices, false);

  while(1) {
    bool continua = false;
    
    for(int i = 0; i < quantidadeVertices; i++) {
      if(!visitados[i]) {
        visitados[i] = true;
        if(DFS(g, g[i], valorBusca, visitados)) return true;

        continua = true;
        break;
      }
    }

    if(!continua) break;
  }

  return false;
}

int main() {
  vertice** grafo = NULL;

  while (true) {
    int op;
    cin >> op;

    if(op == 1) {
      int valorVertice, valorAdjacencia, pesoAdjacencia;
      cin >> valorVertice >> valorAdjacencia >> pesoAdjacencia;

      grafo = InserirVertice(grafo, valorVertice, valorAdjacencia, pesoAdjacencia);
      cout << endl;
    } else if(op == 2) {
      int valor;
      cin >> valor;

      cout << BuscaProfundidade(grafo, valor) << endl;
    } else if(op == 3) {
      return 0;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int numeroVertices = 0;

struct adjacencia;

struct vertice {
  int valor;
  bool visitado;

  adjacencia* adj;
};

struct adjacencia {
  int distancia;
  int verticeAdj;

  adjacencia* listaAdj;
};

void LimpaVisitados(vertice** g) {
  for(int i = 0; i < numeroVertices; i++) {
    g[i]->visitado = false;
  }
}

vertice** InserirVertice(vertice** v, int val1, int val2, int distancia) {
  if(v == NULL) {
    vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
    novoVertice->valor = val1;
    novoVertice->visitado = false;

    adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
    adj->distancia = distancia;
    adj->verticeAdj = val2;
    adj->listaAdj = NULL;

    novoVertice->adj = adj;

    vertice** vetorVertice = (vertice**)malloc(sizeof(vertice*));
    vetorVertice[0] = novoVertice;
    
    numeroVertices++;

    return vetorVertice;
  }

  vertice* verticeInsercao = NULL;
  vertice** percorre_g = v;

  for(int i = 0; i < numeroVertices; i++) {
    if(percorre_g[i]->valor == val1) verticeInsercao = percorre_g[i];
  }

  if(verticeInsercao == NULL) {
    vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
    novoVertice->valor = val1;
    novoVertice->visitado = false;

    adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
    adj->distancia = distancia;
    adj->verticeAdj = val2;
    adj->listaAdj = NULL;

    novoVertice->adj = adj;
    percorre_g = v;

    v[numeroVertices] = novoVertice;
    numeroVertices++;
    return v;
  }

  adjacencia* lista_adj = verticeInsercao->adj;
  adjacencia* nova_adj = (adjacencia*)malloc(sizeof(adjacencia));

  nova_adj->verticeAdj = val2;
  nova_adj->distancia = distancia;
  nova_adj->listaAdj = lista_adj;

  verticeInsercao->adj = nova_adj;
  return v;
}

void ImprimirGrafo(vertice** g) {
  vertice** percorre_g = g;
  int i = 0;

  while(i < numeroVertices) {
    cout << percorre_g[i]->valor << " -> ";

    adjacencia* lista_adj = percorre_g[i]->adj;
    while(lista_adj != NULL) {
      cout << "V" << lista_adj->verticeAdj << " | D(" << lista_adj->distancia << ") -> ";
      lista_adj = lista_adj->listaAdj;
    }

    cout << "NULL" << endl;
    i++;
  }
}

bool ExisteAberto(vertice** g) {
  for(int i = 0; i < numeroVertices; i++) {
    if(!g[i]->visitado) return true;
  }

  return false;
}

void dijkstra(vertice** g, int vInicial, int vFinal, int* d, int* menorCaminho) {
  vertice** percorre_g = g;

  while(ExisteAberto(g)) {
    int menorDist = INT_MAX;
    int indiceMenorDist;

    for(int i = 0; i < numeroVertices; i++) {
      if(d[i] < menorDist && !g[i]->visitado) {
        menorDist = d[i];
        indiceMenorDist = i;
      }
    }

    adjacencia* adj = percorre_g[indiceMenorDist]->adj;
    while(adj != NULL) {
      int indiceAdj;

      for(int j = 0; j < numeroVertices; j++) {
        if(percorre_g[j]->valor == adj->verticeAdj) {
          indiceAdj = j;
          break;
        }
      }

      if(d[indiceAdj] > d[indiceMenorDist] + adj->distancia) {
        d[indiceAdj] = d[indiceMenorDist] + adj->distancia;
        menorCaminho[indiceAdj] = indiceMenorDist;
      }

      adj = adj->listaAdj;
    }

    g[indiceMenorDist]->visitado = true;
  }
}

void CalcularCaminho(vertice** g, int* d, int* menorCaminho, int vFinal) {
  int indiceCaminho;
  int indiceInicial;
  for(int i = 0; i < numeroVertices; i++) {
    if(g[i]->valor == vFinal) {
      indiceCaminho = i;
      break;
    }

    if(d[i] == 0) indiceInicial = i;
  }

  cout << "Menor distancia: " << d[indiceCaminho] << endl << "Caminho: " << vFinal << " ";

  while(g[indiceCaminho] != g[indiceInicial]) {
    cout << g[menorCaminho[indiceCaminho]]->valor << " ";
    indiceCaminho = menorCaminho[indiceCaminho];
  }

  cout << endl;
}

int main() {
  vertice** vetorVertices = NULL;

  int op;
  while(cin >> op) {
    if(op == 1) {
      int u, l, dist;
      cin >> u >> l >> dist;

      vetorVertices = InserirVertice(vetorVertices, u, l, dist);
      vetorVertices = InserirVertice(vetorVertices, l, u, dist);
    } else if(op == 2) {
      ImprimirGrafo(vetorVertices);
    } else if(op == 3) {
      int vInicial, vFinal;
      cin >> vInicial >> vFinal;
      int* d = (int*)malloc(sizeof(int) * numeroVertices);
      int* menorCaminho = (int*)malloc(sizeof(int) * numeroVertices);

      bool verticeInicial = false, verticeFinal = false;
      for(int i = 0; i < numeroVertices; i++) {
        if(vetorVertices[i]->valor == vInicial) {
          verticeInicial = true;
          d[i] = 0;
          menorCaminho[i] = 0;
        } else {
          d[i] = INT_MAX/2;
          menorCaminho[i] = -1;
        }

        if(vetorVertices[i]->valor == vFinal) verticeFinal = true;
       
      }

      if(!verticeInicial || !verticeFinal) cout << "Vertice(s) inexistente(s)." << endl;
      else {
        dijkstra(vetorVertices, vInicial, vFinal, d, menorCaminho);

        CalcularCaminho(vetorVertices, d, menorCaminho, vFinal);
        
        free(d);
        free(menorCaminho);
        LimpaVisitados(vetorVertices);
      }
    }
  }
}
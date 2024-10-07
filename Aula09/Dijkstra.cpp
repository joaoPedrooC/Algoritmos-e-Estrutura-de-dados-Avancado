#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
  int d;

  dijkstra* prox;
  dijkstra* adj;
};

struct adjacencias;

struct No {
  int v;
  bool visitado;

  No* prox;
  adjacencias* adj;
};

struct adjacencias {
  int p;
  
  No* no_adj;
  adjacencias* lista_adj;
};

dijkstra* InsereFila(dijkstra* d, int dist) {
  dijkstra* dj = (dijkstra*)malloc(sizeof(dijkstra));
  dj->d = dist;
  dj->adj = NULL;
  dj->prox = NULL;

  return dj;
}

dijkstra* CalcularDistancia(No* g, dijkstra* dj) {
  adjacencias* p = g->adj;
  dijkstra* d;

  if(dj != NULL) d = dj->adj;
  else d = NULL;

  while(p != NULL) {
    int dist = p->p;
    d = InsereFila(d, dist);

    d->adj = CalcularDistancia(p->no_adj, d->adj);

    p = p->lista_adj;
    d = d->prox;
  }

  return dj;
}

No* VerificarExistencia(No* g, int v) {
  No* p = g;
  while(p != NULL) {
    if(p->v == v) return p;

    p = p->prox;
  }

  return NULL;
}

No* InserirNo(No* g, int u, int v, int l) {
  No* noU = VerificarExistencia(g, u);
  No* noV = VerificarExistencia(g, v);

  if(noU != NULL && noV != NULL) {
    adjacencias* adj = (adjacencias*)malloc(sizeof(adjacencias));
    adj->no_adj = noV;
    adj->p = l;
    adj->lista_adj = noU->adj;

    noU->adj = adj;
    return g;
  } else if(noU != NULL && noV == NULL) {
    noV = (No*)malloc(sizeof(No));
    noV->v = v;
    noV->adj = NULL;
    noV->visitado = false;

    adjacencias* adj = (adjacencias*)malloc(sizeof(adjacencias));
    adj->no_adj = noV;
    adj->p = l;
    adj->lista_adj = noU->adj;

    noU->adj = adj;
    return g;
  }

  noU = (No*)malloc(sizeof(No));
  noU->v = u;
  noU->prox = g;
  noU->visitado = false;

  adjacencias* adj = (adjacencias*)malloc(sizeof(adjacencias));
  adj->p = l;
  adj->lista_adj = NULL;


  if(noV != NULL) {
    adj->no_adj = noV;
    noU->adj = adj;

    return noU;
  }

  noV = (No*)malloc(sizeof(No));
  noV->v = v;
  noV->prox = noU;
  noV->visitado = false;

  noV->adj = NULL;

  adj->no_adj = noV;
  noU->adj = adj;

  return noV;
}

void ImprimirGrafo(No* g) {
  No* p = g;

  while(p != NULL) {
    cout << "No(" << p->v << "): ";

    adjacencias* adj = p->adj;
    while(adj != NULL) {
      cout << adj->no_adj->v << " ";

      adj = adj->lista_adj;
    }

    cout << endl;
    p = p->prox;
  }
}

int main() {
  No* g = NULL;
  
  int op;
  while(cin >> op) {
    if(op == 1) {
      int u, v, l;
      cin >> u >> v >> l;

      g = InserirNo(g, u, v, l);
      g = InserirNo(g, v, u, l);
    } else if(op == 2) {
      ImprimirGrafo(g);
      cout << endl;
    } else if(op == 3) {
      dijkstra* dj = (dijkstra*)malloc(sizeof(dijkstra));
      dj->d = 0;
      dj->adj = NULL;
      dj->prox = NULL;
    }
  }
}
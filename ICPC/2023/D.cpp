#include <bits/stdc++.h>
using namespace std;

int qVertices = 0;

struct adjacencia {
    int vVertice;
    int l;
    adjacencia* lista_adj;
};

struct vertice {
    int v;
    adjacencia* adj;
};

vertice** InsereVertice(vertice** g, int u, int v, int l) {
    if(g == NULL) {
        vertice* vt = (vertice*)malloc(sizeof(vertice));
        vt->v = u;
       
        adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
        adj->vVertice = v;
        adj->l = l;
        adj->lista_adj = NULL;
       
        vt->adj = adj;
       
        qVertices++;
       
        vertice** nG = (vertice**)malloc(sizeof(vertice*));
        nG[0] = vt;
       
        return nG;
    }
   
    vertice* vInsercao = NULL;
    for(int i = 0; i < qVertices; i++) {
        if(g[i]->v == u) vInsercao = g[i];
    }
   
    if(!vInsercao) {
        vertice* vt = (vertice*)malloc(sizeof(vertice));
        vt->v = u;
       
        adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
        adj->vVertice = v;
        adj->l = l;
        adj->lista_adj = NULL;
       
        vt->adj = adj;
       
        g[qVertices] = vt;
       
        qVertices++;
        return g;
    }
   
    adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
    adj->vVertice = v;
    adj->l = l;
    adj->lista_adj = vInsercao->adj;
   
    vInsercao->adj = adj;
   
    return g;
}

bool ExisteAberto(bool* visitados) {
    for(int i = 0; i < qVertices; i++) {
        if(visitados[i] == false) return true;
    }
   
    return false;
}

void Dijkstra(vertice** g, int vInicial, int vFinal, int* d, bool* visitados, pair<int, int> verticeRemovido) {
    while(ExisteAberto(visitados)) {
        int menorDist = INT_MAX;
        int indiceMenorDist;
       
        for(int i = 0; i < qVertices; i++) {
            if(d[i] < menorDist && !visitados[i]) {
                menorDist = d[i];
                indiceMenorDist = i;
            }
        }
       
        adjacencia* adj = g[indiceMenorDist]->adj;
        while(adj != NULL) {
            int indiceAdj;
           
            for(int i = 0; i < qVertices; i++) {
                if(g[i]->v == adj->vVertice) {
                    indiceAdj = i;
                    break;
                }
            }
           
            if(((g[indiceMenorDist]->v != verticeRemovido.first || g[indiceAdj]->v != verticeRemovido.second) && (g[indiceMenorDist]->v != verticeRemovido.second || g[indiceAdj]->v != verticeRemovido.first))) {
                if(d[indiceAdj] > (d[indiceMenorDist] + adj->l)) {
                    d[indiceAdj] = d[indiceMenorDist] + adj->l;
                }
            }
           
            adj = adj->lista_adj;
        }
       
        visitados[indiceMenorDist] = true;
    }
}

void CalcularMenorCaminho(vertice** g, int* d, int vFinal) {
    for(int i = 0; i < qVertices; i++) {
        if(g[i]->v == vFinal) {
            if(d[i] == INT_MAX / 2) cout << -1 << endl;
            else cout << d[i] << endl;
        }
    }
}

void ImprimeGrafo(vertice** g) {
    for(int i = 0; i < qVertices; i++) {
        adjacencia* adj = g[i]->adj;
       
        cout << g[i]->v << ": ";
        while(adj != NULL) {
            cout << adj->vVertice << " | ";
            adj = adj->lista_adj;
        }
       
        cout << endl;
    }
}

int main() {
    vertice** g = NULL;
   
    int n, m;
    cin >> n >> m;
   
    pair<int, int> arrV[m];
   
    for(int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
       
        arrV[i] = { u, v };
       
        g = InsereVertice(g, u, v, l);
        g = InsereVertice(g, v, u, l);
    }
   
    for(int i = 0; i < m; i++) {
        int* d = (int*)malloc(sizeof(int) * qVertices);
        bool* visitados = (bool*)malloc(sizeof(bool) * qVertices);
       
        for(int j = 0; j < qVertices; j++) {
            if(g[j]->v == arrV[i].first) {
                d[j] = 0;
            } else {
                d[j] = INT_MAX / 2;
            }
           
            visitados[j] = false;
        }
       
        Dijkstra(g, arrV[i].first, arrV[i].second, d, visitados, arrV[i]);
        CalcularMenorCaminho(g, d, arrV[i].second);
       
        free(d);
        free(visitados);
    }
}
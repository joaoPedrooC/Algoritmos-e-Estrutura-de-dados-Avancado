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
  if(v == NULL) { // Caso o grafo sera Nulo, preciso criar uma nova raiz (vertice**)
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

  for(int i = 0; i < numeroVertices; i++) { // Verifico se existe um vértice com o valor val1
    if(percorre_g[i]->valor == val1) verticeInsercao = percorre_g[i];
  }

  if(verticeInsercao == NULL) { // Caso não exista, crio um novo vértice e o adiciono ao fim da fila
    vertice* novoVertice = (vertice*)malloc(sizeof(vertice));
    novoVertice->valor = val1;
    novoVertice->visitado = false;

    adjacencia* adj = (adjacencia*)malloc(sizeof(adjacencia));
    adj->distancia = distancia;
    adj->verticeAdj = val2;
    adj->listaAdj = NULL;

    novoVertice->adj = adj;

    v[numeroVertices] = novoVertice;
    numeroVertices++;
    return v;
  }

  // Caso exista, adiciono a nova adjacência ao vértice verticeInserção (adiciono valor val2 ao início da fila)
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

bool ExisteAberto(vertice** g) { // Caso exista um nó g.visitado como sendo false, retorno true (o nó ainda não foi visitado)
  for(int i = 0; i < numeroVertices; i++) {
    if(!g[i]->visitado) return true;
  }

  return false;
}

void dijkstra(vertice** g, int vInicial, int vFinal, int* d, int* menorCaminho) {
  vertice** percorre_g = g;

  while(ExisteAberto(g)) { // Enquanto existirem vértices não visitados o algoritmo deve continuar
    int menorDist = INT_MAX;
    int indiceMenorDist;

    for(int i = 0; i < numeroVertices; i++) { // Consigo a menor distância entre vértice atual e o vértice mais próximo ainda não visitado
      if(d[i] < menorDist && !g[i]->visitado) {
        menorDist = d[i];
        indiceMenorDist = i;
      }
    }

    adjacencia* adj = percorre_g[indiceMenorDist]->adj; // Percorro a lista de adjacência do vértice com menor distâmcia do vértice atual
    while(adj != NULL) {
      int indiceAdj;

      for(int j = 0; j < numeroVertices; j++) { // Consigo o índice da adjacência, para comparar sua distância d[indiceAdj] com o vértice atual d[indiceMenorDist]
        if(percorre_g[j]->valor == adj->verticeAdj) {
          indiceAdj = j;
          break;
        }
      }

      if(d[indiceAdj] > d[indiceMenorDist] + adj->distancia) { // Caso a distância da adjacência > (vértice atual + caminho vAdj), atualizo o menor caminho até o vAdj. 
        d[indiceAdj] = d[indiceMenorDist] + adj->distancia;
        menorCaminho[indiceAdj] = indiceMenorDist;
      }

      adj = adj->listaAdj;
    }

    g[indiceMenorDist]->visitado = true; // Após percorrer o vértice e suas adjacências, marco como visitado para não visitá-lo novamente
  }
}

void CalcularCaminho(vertice** g, int* d, int* menorCaminho, int vFinal) {
  int indiceCaminho;
  int indiceInicial;
  for(int i = 0; i < numeroVertices; i++) {
    if(g[i]->valor == vFinal) { // Encontrando o vértice final para exibir o menor caminho de vFinal -> vInicial
      indiceCaminho = i;
    }

    if(d[i] == 0) indiceInicial = i; // Encontrando o vértice inicial para interromper a iteração de int* menorCaminho
  }

  cout << "Menor distancia: " << d[indiceCaminho] << endl << "Caminho: " << vFinal << " ";

  while(g[indiceCaminho] != g[indiceInicial]) { // Percorre o grafo em vFinal -> vInicial
    cout << g[menorCaminho[indiceCaminho]]->valor << " ";
    indiceCaminho = menorCaminho[indiceCaminho];
  }

  cout << endl;
}

int main() {
  vertice** vetorVertices = NULL; // Inicialização do grafo (Ponteiro de ponteiro)

  int op;
  while(cin >> op) {
    if(op == 1) { // Inserção
      int u, l, dist; // Declaração e leitura dos vértices
      cin >> u >> l >> dist;

      vetorVertices = InserirVertice(vetorVertices, u, l, dist);
      vetorVertices = InserirVertice(vetorVertices, l, u, dist);
    } else if(op == 2) { // Leitura
      ImprimirGrafo(vetorVertices);
    } else if(op == 3) { // Dijkstra
      int vInicial, vFinal; // Vértice em que se iniciará a busca e vértice procurado
      cin >> vInicial >> vFinal;
      int* d = (int*)malloc(sizeof(int) * numeroVertices); // Definição de um array de inteiros para armazenar a distância dos vértices a partir do nó inicial
      int* menorCaminho = (int*)malloc(sizeof(int) * numeroVertices); // Definição de um array de inteiros para armazenar o índice do menor caminho até o nó atual (vInicial = 0)

      bool verticeInicial = false, verticeFinal = false; // Booleanos para evitar a busca de nós inexistentes
      for(int i = 0; i < numeroVertices; i++) {
        if(vetorVertices[i]->valor == vInicial) { // Definição de d[vInicial] = 0 e menorCaminho[vInicial] = 0
          verticeInicial = true;
          d[i] = 0;
          menorCaminho[i] = 0;
        } else { // Definição de d[i] = "ininito" e menorCaminho[i] = "inexistente"
          d[i] = INT_MAX/2;
          menorCaminho[i] = -1;
        }

        if(vetorVertices[i]->valor == vFinal) verticeFinal = true;
      }

      if(!verticeInicial || !verticeFinal) cout << "Vertice(s) inexistente(s)." << endl;
      else {
        dijkstra(vetorVertices, vInicial, vFinal, d, menorCaminho); // Algorítmo de Dijkstra

        CalcularCaminho(vetorVertices, d, menorCaminho, vFinal); // Exibir menor distância na tela
        
        // Liberando memória alocada && limpando visitados para próximo cálculo de distância.
        free(d);
        free(menorCaminho);
        LimpaVisitados(vetorVertices);
      }
    }
  }
}
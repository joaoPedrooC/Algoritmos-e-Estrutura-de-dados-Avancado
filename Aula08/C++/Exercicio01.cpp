#include <bits/stdc++.h>
using namespace std;

struct No {
  No* no_esq;
  int valor;
  No* no_dir;
};

No* InserirNo(No* raiz, int valor) {
  if(raiz == NULL) {
    No* novo_no = (No*)malloc(sizeof(No));
    
    novo_no->valor = valor;
    novo_no->no_dir = NULL;
    novo_no->no_esq = NULL;
    
    return novo_no;
  }

  if(raiz->valor < valor) {
    raiz->no_dir = InserirNo(raiz->no_dir, valor);
  } else {
    raiz->no_esq = InserirNo(raiz->no_esq, valor);
  }

  return raiz;
}

void ImprimirCrescente(No* raiz) {
  if(raiz != NULL) {
    ImprimirCrescente(raiz->no_esq);
    cout << raiz->valor << " ";
    ImprimirCrescente(raiz->no_dir);
  }
}

void ImprimirDecrescente(No* raiz) {
  if(raiz != NULL) {
    ImprimirDecrescente(raiz->no_dir);
    cout << raiz->valor << " ";
    ImprimirDecrescente(raiz->no_esq);
  }
}

bool Buscar(No* raiz, int valor) {
  if(raiz == NULL) return false;

  if(raiz->valor == valor) return true;

  return Buscar(raiz->no_esq, valor) || Buscar(raiz->no_dir, valor);
}

int ContarElementos(No* raiz) {
  if(raiz == NULL) return 0;

  return 1 + ContarElementos(raiz->no_dir) + ContarElementos(raiz->no_esq);
}

int SomarElementos(No* raiz) {
  if(raiz == NULL) return 0;

  return raiz->valor + SomarElementos(raiz->no_esq) + SomarElementos(raiz->no_dir);
}

int ProcurarMaiorElemento(No* raiz) {
  if(raiz == NULL) return -1;

  int maior = raiz->valor;

  int maior_esquerdo = ProcurarMaiorElemento(raiz->no_esq);
  int maior_direito = ProcurarMaiorElemento(raiz->no_dir);

  if(maior_esquerdo > maior) maior = maior_esquerdo;
  if(maior_direito > maior) maior = maior_direito;

  return maior;
}

int ProcurarMenorElemento(No* raiz) {
  if(raiz == NULL) return -1;

  int menor = raiz->valor;
  cout << menor << " ";

  int menor_esquerdo = ProcurarMenorElemento(raiz->no_esq);
  int menor_direito = ProcurarMenorElemento(raiz->no_dir);

  if(menor_direito < menor && menor_direito != -1) {
    menor = menor_direito;
  }

  if(menor_esquerdo < menor && menor_esquerdo != -1) {
    menor = menor_esquerdo;
  }

  return menor;
}

void ImprimirFolhas(No* raiz) {
  if(raiz != NULL) {
    ImprimirFolhas(raiz->no_esq);
    ImprimirFolhas(raiz->no_dir);
    
    if(raiz->no_dir == NULL && raiz->no_esq == NULL) {
      cout << raiz->valor << " ";
    }
  }
}

void ImprimirNaoFolhas(No* raiz) {
  if(raiz != NULL) {
    ImprimirNaoFolhas(raiz->no_esq);
    ImprimirNaoFolhas(raiz->no_dir);
    
    if(raiz->no_dir != NULL || raiz->no_esq != NULL) {
      cout << raiz->valor << " ";
    }
  }
}

No* RemoverNo(No* raiz, int valor) {
  bool encontrado = false;

  No* temp = raiz;
  No* proximo_vertice;
  No* seguinte;
  No* anterior = NULL;
  No* percorre_arvore = raiz;

  while(percorre_arvore != NULL && !encontrado) {
    if(percorre_arvore->valor == valor) {
      encontrado = true;
    } else {
      anterior = percorre_arvore;
  
      if(valor < percorre_arvore->valor) {
        percorre_arvore = percorre_arvore->no_esq;
      } else {
        percorre_arvore = percorre_arvore->no_dir;
      }
    }
  }
  
  if(encontrado) {
    if(percorre_arvore->no_esq == NULL) proximo_vertice = percorre_arvore->no_dir;
    else {
      if(percorre_arvore->no_dir == NULL) proximo_vertice = percorre_arvore->no_esq;
      else {
        temp = percorre_arvore;
        proximo_vertice = percorre_arvore->no_dir;
        seguinte = proximo_vertice->no_esq;

        while(seguinte != NULL) {
          temp = proximo_vertice;
          proximo_vertice = seguinte;
          seguinte = proximo_vertice->no_esq;
        }

        if(temp != percorre_arvore) {
          temp->no_esq = proximo_vertice->no_dir;
          proximo_vertice->no_dir = percorre_arvore->no_dir;
          percorre_arvore->no_dir = NULL;
        }

        proximo_vertice->no_esq = percorre_arvore->no_esq;
        percorre_arvore->no_esq = NULL;
      }
    }

    if(anterior == NULL) { // Aqui há substituição da raiz.
      return proximo_vertice;
    } else { // Caso não o número a ser excluido não seja a raiz.
      if(proximo_vertice != NULL) {
        if(proximo_vertice->valor > anterior->valor) {
          anterior->no_dir = proximo_vertice;
        } else {
          anterior->no_esq = proximo_vertice;
        }
      } else { // Caso próximo vértice seja nulo, elimino um ramo.
        if(anterior->no_dir == percorre_arvore) anterior->no_dir = NULL;
        else anterior->no_esq = NULL;
      }

      return raiz;
    }
  }
}

int main() {
  No* raiz = NULL;
  
  while (true)
  {
    int opcao;

    cout << "\n1.Inserir\n2.Busca\n3.Imprimir O. Crescente\n4.Imprimir O. Decrescente\n5.Contar Elementos\n6.Somar Elementos\n7.Encontrar Menor\n8.Encontrar Maior\n9.Imprimir Folhas\n10.Imprimir Nao Folhas\n11.Remover:\n";
    cin >> opcao;

    if(opcao == 1) {
      int valor;
      cin >> valor;

      raiz = InserirNo(raiz, valor);
    } else if(opcao == 2) {
      int valor;
      cin >> valor;

      bool resultado = Buscar(raiz, valor);
      cout << "Resultado: " << resultado << endl;
    } else if(opcao == 3) {
      ImprimirCrescente(raiz);
    } else if(opcao == 4) {
      ImprimirDecrescente(raiz);
    } else if(opcao == 5) {
      int resultado = ContarElementos(raiz);
      cout << "Resultado: " << resultado << endl;
    } else if(opcao == 6) {
      int resultado = SomarElementos(raiz);
      cout << "Resultado: " << resultado << endl;
    } else if(opcao == 7) {
      int resultado = ProcurarMenorElemento(raiz);
      cout << "Menor: " << resultado << endl;
    } else if(opcao == 8) {
      int resultado = ProcurarMaiorElemento(raiz);
      cout << "Maior: " << resultado << endl;
    } else if(opcao == 9) {
      ImprimirFolhas(raiz);
    } else if(opcao == 10) {
      ImprimirNaoFolhas(raiz);
    } else if(opcao == 11) {
      int valor;
      cin >> valor;

      raiz = RemoverNo(raiz, valor);
      ImprimirCrescente(raiz);
    } else {
      cout << "Opcao invalida." << endl;
    }
  }
  

  return 0;
}
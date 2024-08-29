#include <bits/stdc++.h>
using namespace std;

typedef struct ArvoreBinaria {
  ArvoreBinaria* no_esq;
  int valor;
  ArvoreBinaria* no_dir;
} arv;

ArvoreBinaria* InserirNo(ArvoreBinaria* raiz, int valor) {
  if(raiz == NULL) {
    ArvoreBinaria* novaRaiz;
    
    novaRaiz = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));

    novaRaiz->valor = valor;
    novaRaiz->no_esq = NULL;
    novaRaiz->no_dir = NULL;

    return novaRaiz;
  }

  if(raiz->valor < valor) {
    raiz->no_dir = InserirNo(raiz->no_dir, valor);
  } else {
    raiz->no_esq = InserirNo(raiz->no_esq, valor);
  }

  return raiz;
}

bool ProcurarNo(ArvoreBinaria* raiz, int valor) {
  if(raiz == NULL) return false;
  if(raiz->valor == valor) return true;

  bool encontrado = ProcurarNo(raiz->no_dir, valor) || ProcurarNo(raiz->no_esq, valor);

  return encontrado;
}

int main() {
  ArvoreBinaria* raiz = NULL;

  while (true) {
    int opcao;

    cout << "1. Inserir\n2. Procurar" << endl;
    cin >> opcao;

    if(opcao == -1) break;
    else if(opcao == 1) {
      int valor;

      cout << "Digite o valor que deseja inserir: ";
      cin >> valor;
      
      raiz = InserirNo(raiz, valor);
    } else if(opcao == 2) {
      int valor;

      cout << "Digite o valor que deseja procurar: ";
      cin >> valor;

      bool encontrado = ProcurarNo(raiz, valor);
      cout << "Resultado: " << (bool)encontrado << endl;
    }
  }
  

  return 0;
}
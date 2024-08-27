#include <bits/stdc++.h>
using namespace std;

#define TAMANHO 10

typedef struct Alunos {
  string nome;
  string curso;
  int idade;
} al;

void bubble_sort(al aluno[], int n) {
  al aux;

  for(int i = 0; i < n; i++) {
  bool ordenado = true;
    
    for(int j = 0; j < n - 1; j++) {

      if(aluno[j].nome != aluno[j + 1].nome && aluno[j].nome > aluno[j + 1].nome) {
        aux = aluno[j];
        aluno[j] = aluno[j + 1];
        aluno[j + 1] = aux;

        ordenado = false;
      } else if(aluno[j].nome == aluno[j + 1].nome && aluno[j].idade > aluno[j + 1].idade) {
        aux = aluno[j];
        aluno[j] = aluno[j + 1];
        aluno[j + 1] = aux;

        ordenado = false;
      }

    }

    cout << "aqui\n\n\n";
    if(ordenado) break;
  }
}

void imprimir_alunos(al aluno[], int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    cout << "[ Nome -> " << aluno[i].nome << " ; Idade -> " << aluno[i].idade << " ; Curso -> " << aluno[i].curso << " ]" << endl;
  }

  cout << endl << endl;
}

int main() {
  al alunos[TAMANHO];

  for(int i = 0; i < TAMANHO; i++) {
    string nome, curso;
    int idade;

    cout << "Nome do aluno: ";
    cin >> nome;

    cout << "Curso do aluno: ";
    cin >> curso;

    cout << "Idade do aluno: ";
    cin >> idade;

    alunos[i].nome = nome;
    alunos[i].curso = curso;
    alunos[i].idade = idade;
  }

  cout << "Antes da ordenacao:\n";
  imprimir_alunos(alunos, TAMANHO);

  clock_t inicio = clock();

  bubble_sort(alunos, TAMANHO);

  clock_t fim = clock();

  cout << "Apos ordenacao:\n";
  imprimir_alunos(alunos, TAMANHO);

  float tempoGasto = (float)( fim - inicio ) / CLOCKS_PER_SEC;
  cout << "Tempo gasto -> " << tempoGasto << " segundos." << endl;
}
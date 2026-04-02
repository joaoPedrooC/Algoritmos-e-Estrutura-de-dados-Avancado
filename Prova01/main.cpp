#include <bits/stdc++.h>
#include "./bubbleSort.cpp"
#include "./insertionSort.cpp"
#include "./selectionSort.cpp"
#include "./mergeSort.cpp"
#include "./quickSort.cpp"

using namespace std;

#define SEP_SIZE 50

struct timeComparison {
  string methodName;
  double executionTime;
};

void imprime_sep(int n) {
  for (int i = 0; i < n; i++) {
    cout << "*";
  }

  cout << endl;
}

void imprime_menu() {
  imprime_sep(SEP_SIZE);
  cout << "Menu de opções:" << endl;
  cout << "1. Bubble sort;" << endl;
  cout << "2. Insertion sort;" << endl;
  cout << "3. Selection sort;" << endl;
  cout << "4. Merge sort;" << endl;
  cout << "5. Quick sort;" << endl;
  cout << "6. Comparativo de tempo de execução;" << endl;
  cout << "7. Sair." << endl;
  imprime_sep(SEP_SIZE);
}

void imprime_lista(int vetor[], int n) {
  for (int i = 0; i < n; i++) {
    cout << vetor[i] << " ";
  }

  cout << endl;
}

struct timeComparison handle_time_comparison() {
  string name = "teste";
  double s = 1.2;
  timeComparison tcp;
  tcp.executionTime = s;
  tcp.methodName = name;
  return tcp;
}

void print_time_comparison(struct timeComparison comparison) {
  // pass
  return;
}

int main() {
  while (1) {
    imprime_menu();

    int chosenOption;
    cin >> chosenOption;

    if (chosenOption == 7) break;
    else if (chosenOption == 6) {
      print_time_comparison(handle_time_comparison());
      continue;
    }

    int amountOrdering;
    cout << "Quantos números serão ordenados? ";
    cin >> amountOrdering;

    int orderingVet[amountOrdering];

    int wannaManuallyInsert;
    cout << "Você deseja escolher os números manualmente ou gostaria que fossem gerados aleatóriamente? (1 - Escolher | 2 - Aleatório) ";
    cin >> wannaManuallyInsert;

    if (wannaManuallyInsert == 1) {
      for (int i = 0; i < amountOrdering; i++) {
        cin >> orderingVet[i];
      }
    } else {
      for (int i = 0; i < amountOrdering; i++) {
        orderingVet[i] = rand() % 100;
      }
    }

    cout << endl;
    imprime_sep(SEP_SIZE);
    cout << "Lista antes da ordenação: ";
    imprime_lista(orderingVet, amountOrdering);
    imprime_sep(SEP_SIZE);

    if (chosenOption == 1) bubble_sort(orderingVet, amountOrdering, imprime_lista);
    else if(chosenOption == 5) quick_sort(orderingVet, 0, amountOrdering, imprime_lista);
  }
  return 0;
}
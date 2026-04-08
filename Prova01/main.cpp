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
  int runType; // 0 for 10k 1 for 30k
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

vector<int> generate_random_numbers(int vecSize) {
  vector<int> randomVec(vecSize);
  for(int i = 0; i < vecSize; i++) {
    randomVec[i] = rand();
  }

  return randomVec;
}

void handle_time_comparison(struct timeComparison *timeCp) {
  imprime_sep(SEP_SIZE);
  cout << "Ordenando vetor original [TAMANHO 10.000]:" << endl;
  imprime_sep(SEP_SIZE);
  
  string sort_types[] = {"bubble_sort", "insertion_sort", "selection_sort", "merge_sort", "quick_sort"};
  int idx = 0;
  for(string i : sort_types) {
    vector<int> firstVector = generate_random_numbers(10000);
    int *firstNumberSet = firstVector.data();
    clock_t inicio = clock();
    
    if(i == "bubble_sort") {
      bubble_sort(firstNumberSet, 10000, imprime_lista, false);
    } else if(i == "insertion_sort") {
      insertion_sort(firstNumberSet, 10000, imprime_lista, false);
    } else if(i == "selection_sort") {
      selection_sort(firstNumberSet, 10000, imprime_lista, false);
    } else if(i == "merge_sort") {
      merge_sort(firstNumberSet, 10000, imprime_lista, false);
    } else {
      quick_sort(firstNumberSet, 0, 10000, imprime_lista, false);
    }
    
    float time = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    
    struct timeComparison temp;
    temp.executionTime = time;
    temp.methodName = sort_types[idx];
    temp.runType = 0;
    
    timeCp[idx] = temp;

    idx++;
  }
  
  // ============================================================================================================
  
  cout << endl << endl;
  
  imprime_sep(SEP_SIZE);
  cout << "Ordenando vetor original [TAMANHO 30.000]:" << endl;
  imprime_sep(SEP_SIZE);
  
  int sort_idx = 0;
  for(string i : sort_types) {
    vector<int> secondVector = generate_random_numbers(30000);
    int *secondNumberSet = secondVector.data();

    clock_t inicio = clock();
    if(i == "bubble_sort") {
      bubble_sort(secondNumberSet, 30000, imprime_lista, false);
    } else if(i == "insertion_sort") {
      insertion_sort(secondNumberSet, 30000, imprime_lista, false);
    } else if(i == "selection_sort") {
      selection_sort(secondNumberSet, 30000, imprime_lista, false);
    } else if(i == "merge_sort") {
      merge_sort(secondNumberSet, 30000, imprime_lista, false);
    } else {
      quick_sort(secondNumberSet, 0, 30000, imprime_lista, false);
    }
    
    float time = (double)(clock() - inicio) / CLOCKS_PER_SEC;

    struct timeComparison temp;
    temp.executionTime = time;
    temp.methodName = sort_types[sort_idx];
    temp.runType = 1;

    timeCp[idx] = temp;

    idx++;
    sort_idx++;
  }
}

void print_time_comparison(struct timeComparison comparison[]) {
  sort(comparison, comparison + 10, [](struct timeComparison a, struct timeComparison b) {
    if (a.runType != b.runType) {
      return a.runType < b.runType;
    }

    return a.executionTime < b.executionTime;
  });

  for(int i = 0; i < 10; i++) {
    struct timeComparison timeCp = comparison[i];
    if(timeCp.runType != 0) continue;

    cout << "Método [" << timeCp.methodName << "] | Tempo de Execucao: " << timeCp.executionTime << "s" << endl;
  }

  cout << endl;
  imprime_sep(SEP_SIZE);
  cout << endl;

  for(int i = 0; i < 10; i++) {
    struct timeComparison timeCp = comparison[i];
    if(timeCp.runType != 1) continue;

    cout << "Método [" << timeCp.methodName << "] | Tempo de Execucao: " << timeCp.executionTime << "s" << endl;
  }

  cout << endl << endl;
  return;
}

int main() {
  while (1) {
    imprime_menu();

    int chosenOption;
    cin >> chosenOption;

    if (chosenOption == 7) break;
    else if (chosenOption == 6) {
      struct timeComparison timeCp[10];
      handle_time_comparison(timeCp);
      print_time_comparison(timeCp);
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

    if (chosenOption == 1) bubble_sort(orderingVet, amountOrdering, imprime_lista, true);
    else if (chosenOption == 2) insertion_sort(orderingVet, amountOrdering, imprime_lista, true);
    else if (chosenOption == 3) selection_sort(orderingVet, amountOrdering, imprime_lista, true);
    else if(chosenOption == 4) merge_sort(orderingVet, amountOrdering, imprime_lista, true);
    else if(chosenOption == 5) quick_sort(orderingVet, 0, amountOrdering, imprime_lista, true);
  }
  return 0;
}
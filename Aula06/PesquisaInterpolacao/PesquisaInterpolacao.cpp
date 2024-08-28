int pesquisaInterpolacao(int chave, int v[], int n) {
  int ini = 0;
  int meio;
  int fim = n - 1;

  while(ini <= fim) {
    meio = ini + ((fim - ini) * (chave-v[ini])) / (v[fim] - v[ini]);

    if(chave < v[meio]) fim = meio - 1;
    else if(chave > v[meio]) ini = meio + 1;
    else return meio;
  }

  return -1;
}
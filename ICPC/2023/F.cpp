#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, qtdC, qtdR;
  cin >> d >> qtdC >> qtdR;

  int c[qtdC], r[qtdR];

  for(int i = 0; i < qtdC; i++) {
    cin >> c[i];
  }

  for(int i = 0; i < qtdR; i++) {
    cin >> r[i];
  }

  int atividades = 0;

  while(true) {
    bool possivel = false;
    for(int i = 0; i < qtdC; i++) {
      if(c[i] <= d && c[i] > 0) {
        d -= c[i];
        c[i] = -1;

        possivel = true;

        atividades++;
      } else if(c[i] > 0 && d < c[i]) break;
    }

    if(!possivel) {
      for(int i = 0; i < qtdR; i++) {
        if(r[i] != -1) {
          d += r[i];
          r[i] = -1;

          possivel = true;

          atividades++;
          break;
        }
      }
    }

    if(!possivel) break;
  }

  cout << atividades << endl;
}
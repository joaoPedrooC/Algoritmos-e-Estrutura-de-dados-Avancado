#include <bits/stdc++.h>
using namespace std;

int main() {
  int qtd, pos;
  cin >> qtd >> pos;

  int flores[qtd];
  for(int i = 0; i < qtd; i++) {
    cin >> flores[i];
  }

  for (int i = 0; i < pos; i++) {
    int maior = 0;

    for(int j = 1; j < qtd; j++) {
      if(flores[maior] < flores[j]) maior = j;
    }

    int polen = flores[maior];
    int totalPolen = 0;

    while(polen > 0) {
      totalPolen += polen%10;
      polen /= 10;
    }
    
    flores[maior] -= totalPolen;
    
    if(i == (pos - 1)) cout << totalPolen << endl;
  }
}
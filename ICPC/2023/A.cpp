#include <bits/stdc++.h>
using namespace std;

int main() {
  int qtd, altura;
  cin >> qtd >> altura;

  int total = 0;

  while(qtd > 0) {
    int a;
    cin >> a;

    if(altura >= a) total++;

    qtd--;
  }

  cout << total << endl;
}
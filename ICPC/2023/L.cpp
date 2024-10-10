#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;

  cin >> s >> k;

  while(true) {
    bool alt = false;
    for(int i = 0; i < s.size() && ((i + k) <= s.size() - 1); i++) {
      if(s[i] > s[i + k]) {
        char temp = s[i + k];
        s[i + k] = s[i];
        s[i] = temp;

        alt = true;
      }
    }

    if(!alt) break;
  }

  cout << s << endl;
}
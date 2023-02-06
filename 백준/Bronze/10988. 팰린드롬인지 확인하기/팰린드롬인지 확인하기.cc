#include <bits/stdc++.h>

using namespace std;


int main() {
  string s;
  cin >> s;
  int k = s.length() / 2;
  bool ret = true;
  for (int i = 0; i < k; i++) {
    if (s[i] != s[s.length() - i -1]) {
      ret = false;
      break;
    }
  }
  if(ret) cout <<  1 << '\n';
  else cout << 0 << '\n';
  return 0;
}
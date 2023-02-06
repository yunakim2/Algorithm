#include <bits/stdc++.h>

using namespace std;

int main() {
  int num;
  cin >> num;
  int alpha[26] = {0,};
  string s;
  for (int i = 0; i < num; i++) {
    cin >> s;
    alpha[s[0]-'a'] ++;
  }
  bool ret = false;
  for (int j = 0; j < 26; j++) {
    if (alpha[j] >= 5) {
      cout << char(j + 97);
      ret = true;
    }
  }
  if(!ret) cout << "PREDAJA";

  return 0;
}
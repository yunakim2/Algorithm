#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  for (auto i : s) {
    if (i >= 65 && i <= 90) {
      if (i + 13 > 90) {
        cout << char(i + 13 - 26);
        continue;
      }
      cout << char(i + 13);
    } else if (i >= 97 && i <= 122) {
      if (i + 13 > 122) {
        cout << char(i + 13 - 26);
        continue;
      }
      cout << char(i + 13);
    } else {
      cout << i;
    }
  }

  return 0;
}
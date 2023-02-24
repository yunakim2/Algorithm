#include <bits/stdc++.h>

using namespace std;
int N;

int main() {
  cin >> N;
  for (int i = 666; ; i++) {
    if (to_string(i).find("666") != string::npos) {
      N--;
      if (N == 0) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') cnt += 1;
    else cnt -= 1;
    if (cnt < 0) cout << "NO"; return;
  }
  if (cnt == 0) cout << "YES";
  else cout << "NO";
}
#include <bits/stdc++.h>

using namespace std;
int N;
string s;

bool checking(string s) {
  stack<char> stacks;
  for (auto c : s) {
    if ( c == '(') stacks.push(c);
    else {
      if(stacks.empty()) return false;
      stacks.pop();
    }
  }
  return stacks.empty();
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (checking(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
#include <bits/stdc++.h>

using namespace std;

bool checking(string s) {
  stack<char> stacks;
  if (s.find('[') == string::npos && s.find(']') == string::npos && s.find(')') == string::npos && s.find('(') == string::npos) {
    return true;
  }
  bool check = true;
  for (auto c : s) {
    if (c == ')') {
      if (stacks.size() == 0 || stacks.top() == '[') {
        check = false;
        break;
      }
      else stacks.pop();
    }
    if (c == ']') {
      if (stacks.size() == 0 || stacks.top() == '(') {
        check = false;
        break;
      }
      else stacks.pop();
    }
    if (c == '(') stacks.push(c);
    if (c == '[') stacks.push(c);
  }

  return check && stacks.empty();
}

int main() {
  string s;
  while (true) {
    getline(cin, s);
    if (s == ".") break;
    if (checking(s)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
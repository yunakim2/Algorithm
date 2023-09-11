#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, ans = "";
  getline(cin , s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') continue;
    if (isupper(s[i])) ans += tolower(s[i]);
    else ans += s[i];
  }

  cout << ans;
}
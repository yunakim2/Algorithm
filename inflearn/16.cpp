#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> m1;
map<char, int> m2;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  if (s1.length() != s2.length()) {
    cout << "NO";
  } else {
    for (int i = 0; i < s1.length(); i++) {
      if (m1.find(s1[i]) == m1.end()) {
        m1.insert({s1[i], 1});
      } else {
        m1[s1[i]] += 1;
      }
    }

    for (int i = 0; i < s2.length(); i++) {
      if (m2.find(s2[i]) == m2.end()) {
        m2.insert({s2[i], 1});
      } else {
        m2[s2[i]] += 1;
      }
    }

    bool checking = true;
    for (auto data : m1) {
      if (data.second != m2[data.first]) {
        checking = false;
        break;
      }
    }
   if (checking) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}
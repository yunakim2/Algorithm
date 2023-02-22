#include <bits/stdc++.h>

using namespace std;
int N; 
vector<string> v;

bool cmp(string a, string b) {
  if (a.length() == b.length()) return a < b;
  return a.length() < b.length();

}

string removeZero(string s) {
  int pos = -1;
  pos = s.find_first_not_of('0');
  if (pos == -1 && s.back() == '0') return "0";
  return s.erase(0, pos);
}

int main() {
  cin >> N;
  string s;
  string temp = "";
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      if (97 <= s[j] && s[j] <= 122) {
        if (temp != "") {
          v.push_back(removeZero(temp));
          temp = "";
        } else {
          continue;
        }
      } else {
        temp += s[j];
      }
    }
    if (temp != "") {
      v.push_back(removeZero(temp));
      temp = "";
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) {
    cout << i << '\n';
  }
}
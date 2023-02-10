#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N, cnt = 0;
  cin >> N;
  string str;
  for (int i = 0; i < N; i++) {
    vector<char> v;
    cin >> str;
    for (auto s : str) {
      if (v.empty()) {
        v.push_back(s);
      } else {
        if (s == v.back()) {
          v.pop_back();
        } else {
          v.push_back(s);
        }
      }
    }
    if (v.empty()) cnt += 1;
  }
  cout << cnt << '\n';
  return 0;
}
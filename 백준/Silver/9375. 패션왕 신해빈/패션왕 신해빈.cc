#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    map<string, int> dress;
    for (int j = 0; j < n; j++) {
      string name, count;
      cin >> name >> count;
      if (dress.find(count) == dress.end()) {
        dress[count] = 1;
      } else {
        dress[count] += 1;
      }
    }
    int sums = 1;
    for (auto cnt : dress) {
      sums *= (cnt.second + 1);
    }
    cout << sums - 1 << '\n';
  }
  return 0;
}
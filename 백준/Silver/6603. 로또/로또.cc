#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    vector<int> v;
    vector<int> checking;
    for (int i = 0; i < n; i++) {
      int nn;
      cin >> nn;
      v.push_back(nn);
      if (i < 6) {
        checking.push_back(0);
      } else {
        checking.push_back(1);
      }
    }
    do {
      for (int i = 0; i < v.size(); i++) {
        if (checking[i] == 0) {
          cout << v[i] << " ";
        }
      }
      cout << "\n";
    } while(next_permutation(checking.begin(), checking.end()));
      cout << "\n";
  }

}
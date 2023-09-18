#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1.size() != s2.size()) {
      cout << "Impossible" << "\n";
      continue;
    }
    bool checking = true;
    for (int i = 0; i < s1.size(); i++) {
      if(s1[i] != s2[i]) {
        checking = false;
        break;
      }
    }
    if (checking) {
      cout << "Possible" << "\n";
    } else {
      cout << "Impossible" << "\n";
    }
  }
}
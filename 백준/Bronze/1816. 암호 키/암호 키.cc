#include <iostream>

using namespace std;

int main() {
  long long  n, num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    for (int k = 2; k <= 1000000; k++) {
      if (num % k == 0) {
        cout << "NO\n";
        break;
      }
      if (k == 1000000) {
        cout << "YES\n";
      }
    }
  }
}
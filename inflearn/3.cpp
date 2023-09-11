#include <iostream>

using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      if (i != 1) cout << "+ ";
      cout << i << " ";
      sum += i;
    }
  }
  cout << "= " << sum;
}
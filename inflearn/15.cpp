#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n == 1) return false;
  else if (n == 2) return true;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int N, cnt = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (isPrime(i)) cnt += 1;
  }
  cout << cnt;
}
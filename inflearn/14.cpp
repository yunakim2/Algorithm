#include <iostream>
#include <string>

using namespace std;

bool isPrime(int x) {
  if (x == 1) return false;
  else if (x == 2) return true;
  for (int i = 2; i < x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int reverse(int x) {
  string s = to_string(x);
  string rev_s = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    if (i == '0' && rev_s == "") {
      continue;
    }
    rev_s += s[i];
  }
  return stoi(rev_s);
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    if (isPrime(reverse(n))) {
       cout << reverse(n) << " ";
    }
  }
}
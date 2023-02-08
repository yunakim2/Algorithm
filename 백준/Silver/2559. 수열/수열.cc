#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k;
  string s;
  int num[100004];
  int psum[100004];
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    psum[i] = psum[i-1] + num[i];
  }
  int maximum[100004];
  int largest = -1000000;
  for (int i = k; i <= n; i++) {
      largest = max(largest, psum[i]-psum[i-k]);
  }
  cout << largest << '\n';
  return 0;
}
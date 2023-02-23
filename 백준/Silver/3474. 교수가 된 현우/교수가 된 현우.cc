#include <bits/stdc++.h>

using namespace std;
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> N;
  int n;
  for (int i = 0; i < N; i++) {
    cin >> n;
    int num = 0;
    for (int k = 5; k <= n; k *= 5) {
      num += n/k;
    }
    cout << num << '\n';
  }
}
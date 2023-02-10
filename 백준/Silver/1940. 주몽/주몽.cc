#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N;
  int M;
  cin >> N;
  cin >> M;
  int arr[150004];
  int cnt = 0;
  for (int i = 0; i < N ; i++) cin >> arr[i];
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      if (arr[i] + arr[j] == M) {
        cnt += 1;
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
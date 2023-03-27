#include <bits/stdc++.h>

using namespace std;

int T[16];
int P[16];
int N;
int ans = 0;

void dfs(int start, int sums) {
  if (start == N+1) {
    ans = max(ans, sums);
    return;
  }
  if (start > N+1) return;

  dfs(start + T[start], sums + P[start]);
  dfs(start + 1, sums);
}

int main() {
  cin >> N;
  int temp_t, temp_p;
  for (int i = 1; i <= N; i++) {
    cin >> temp_t >> temp_p;
    T[i] = temp_t;
    P[i] = temp_p;
  }

  dfs(1,0);

  cout << ans;
}
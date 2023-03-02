#include <bits/stdc++.h>

using namespace std;
vector<int> v[10004];
int visited[10004];
int dp[10004];

int dfs(int start) {
  visited[start] = 1;
  int ret = 1;
  for (int there : v[start]) {
    if(visited[there]) continue;
    ret += dfs(there);
  }
  return ret;
}

int main() {

  int n, m;
  cin >> n >> m;
  int k, j;
  for (int i = 0; i < m; i++) {
    cin >> k >> j;
    v[j].push_back(k);
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    memset(visited, 0, sizeof(visited));
    dp[i] = dfs(i);
    mx = max(mx, dp[i]);
  }

  for(int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << ' ';
  return 0;
}
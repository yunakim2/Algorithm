#include <bits/stdc++.h>

using namespace std;
int N;
int s1, s2;
vector<int> arr[104];
int ans;
int visited[104];

void dfs(int now, int end, int cnt) {
  if (now == end) {
    ans = cnt; 
    return;
  }
  visited[now] = 1;
  for (int next : arr[now]) {
    if (!visited[next]) {
      dfs(next, end, cnt + 1);
    }
  }
  return;
}


int main() {

  cin >> N;
  cin >> s1 >> s2;
  int n;
  cin >> n;

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    arr[y].push_back(x);
    arr[x].push_back(y);
  }

  dfs(s1, s2, 0);

  if (ans != 0) {
    cout << ans;
  } else {
    cout << "-1";
  }
}
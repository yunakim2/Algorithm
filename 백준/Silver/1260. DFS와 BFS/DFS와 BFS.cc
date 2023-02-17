#include <bits/stdc++.h>

using namespace std;
int N, M, V;
int arr[1004][1004];
int visited[1004];
queue<int> q;

void dfs(int start) {
  if(!visited[start]) return;
  visited[start] = 0;
  cout << start << ' ';
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) continue;
    if (!arr[start][i]) continue;
    dfs(i);
  }
  return;
}

void bfs(int start) {
  q.push(start);
  visited[start] = 0;
  cout << start << ' ';
  while (q.size()) {
    int next = q.front();
    q.pop();
    for (int i = 1; i <= N; i++) {
      if (visited[i] && arr[next][i]) {
        cout << i<< ' ';
        visited[i] = 0;
        q.push(i);
      }
    }
  }
  
}

int main() {
  cin >> N >> M >> V;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  for (int i = 1; i <= N; i++) {
    visited[i] = 1;
  }

  dfs(V);
  cout << '\n';
 for (int i = 1; i <= N; i++) {
    visited[i] = 1;
  }
  bfs(V);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[104][104];
int N, M;
int visited[104][104];
int dist[104][104];
queue<pair<int,int>> q;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void bfs(int x, int y) {
  q.push({x, y});
  visited[x][y] = 1;
  dist[x][y] = 1;
  while (q.size()) {
    int nx = q.front().first;
    int ny = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int mx = nx + dx[i];
      int my = ny + dy[i];
      if (mx >= 0 && mx < N && my >= 0 && my < M && !visited[mx][my] && arr[mx][my] == 1) {
        q.push({mx, my});
        visited[mx][my] = 1;
        dist[mx][my] = dist[nx][ny] + 1;
      }
    }
  }
}

int main() {
  cin >> N >> M;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      arr[i][j] =s[j] - '0';
    }
  }
  bfs(0,0);
  cout << dist[N-1][M-1] << '\n';
  return 0;
}
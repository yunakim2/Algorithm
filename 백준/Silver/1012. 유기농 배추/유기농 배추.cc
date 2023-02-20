#include <bits/stdc++.h>

using namespace std;

int T, N, M, K;
int arr[50][50];
int visited[50][50];
queue<pair<int, int>> q;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
void makeMap() {
  while(!q.empty()) q.pop();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      arr[i][j] = 0;
      visited[i][j] = 0;
    }
  }
  
}

void bfs(int xx, int yy) {
  q.push({xx, yy});
  visited[xx][yy] = 1;
  while (q.size()) {
    auto txy = q.front(); q.pop();
    int x = txy.first;
    int y = txy.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || nx >= M || 0 > ny || ny >= N) {
        continue;
      }
      if (arr[nx][ny] == 1 && !visited[nx][ny]) {
        visited[nx][ny] = 1;
        q.push({nx,ny});
      }
    }
  }
}


int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> K;
    makeMap();
    int cnt = 0;
    for (int m = 0; m < K; m++) {
      int a,b;
      cin >> a >> b;
      arr[a][b] = 1;
    }
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < N; k++) {
        if (arr[j][k] == 1 && !visited[j][k]) {
          bfs(j, k);
          cnt+=1;
        }
      }
    }
    cout << cnt << '\n';

  }
  return 0;
}
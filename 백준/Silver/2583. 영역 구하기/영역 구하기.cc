#include <bits/stdc++.h>

using namespace std;
int M, N, K;
int lx,ly, rx, ry;
int arr[101][101];
int visited[101][101];
queue<pair<int, int>> q;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void fillRect() {
  for (int i = lx; i < rx; i++) {
    for (int j = ly; j < ry; j++) {
      arr[j][i] = 1;
    }
  }
}

int bfs(int xx, int yy) {
  q.push({xx,yy});
  visited[xx][yy] = 1;
  int cnt = 1;
  while (q.size()) {
    auto xy = q.front(); q.pop();
    int x = xy.first;
    int y = xy.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || nx >= M || 0 > ny || ny >= N) continue;
      if (arr[nx][ny] == 0 && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = 1;
        cnt += 1;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> M >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> lx >> ly >> rx >> ry;
    fillRect();
  }


  vector<int> cnt;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == 0 && !visited[i][j]) {
        cnt.push_back(bfs(i, j));
      }
    }
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt.size() << "\n";
  for (int i : cnt) {
    cout << i << ' ';
  }
  return 0;
}
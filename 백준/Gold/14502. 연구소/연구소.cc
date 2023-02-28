#include <bits/stdc++.h>

using namespace std;

int real_arr[9][9];
int N, M;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int bfs() {
  int arr[9][9];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      arr[i][j] = real_arr[i][j];
    }
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 2) {
       q.push({i, j});
      }
    }
  }

  while (q.size()) {
    auto xy = q.front(); q.pop();
    int x = xy.first;
    int y = xy.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || N <= nx || 0 > ny || M <= ny) continue;
      if (arr[nx][ny] == 0) {
        q.push({nx, ny});
        arr[nx][ny] = 2;
      }
    }
  }

  
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 0) {
        cnt += 1;
      }
    }
  }
  return cnt;
}

int main() {
  
  cin >> N >> M;
  int a;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a;
      real_arr[i][j] = a;
    }
  }
  int max_cnt = 0;
  for (int x1 = 0; x1 < N; x1++) {
    for (int y1 = 0; y1 < M; y1++) {
      if (real_arr[x1][y1] != 0) continue;
      for (int x2 = 0; x2 < N; x2++) {
        for (int y2 = 0; y2 < M; y2++) {
          if (real_arr[x2][y2] != 0) continue;
          for (int x3 = 0; x3 < N; x3++) {
            for (int y3 = 0; y3 < M; y3++) {
              if (real_arr[x3][y3] != 0) continue;
              if (x1 == x2 && y1 == y2) continue;
              if (x2 == x3 && y2 == y3) continue;
              if (x3 == x1 && y3 == y1) continue;
              real_arr[x1][y1] = 1;
              real_arr[x2][y2] = 1;
              real_arr[x3][y3] = 1;
              max_cnt = max(max_cnt, bfs());
              real_arr[x1][y1] = 0;
              real_arr[x2][y2] = 0;
              real_arr[x3][y3] = 0;
              
            }
          }
        }
      }
    }
  }

  cout << max_cnt << '\n';

}
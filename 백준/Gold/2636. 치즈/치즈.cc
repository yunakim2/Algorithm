#include<bits/stdc++.h>

using namespace std;

int arr[101][101];
int N, M;
vector<int> cheese_cnt;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
queue<pair<int, int>> q;

int bfs() {
  int visited[101][101] = {0, };
  q.push({0,0});

  while (q.size()) {
    auto xy = q.front(); q.pop();
    int x = xy.first;
    int y = xy.second;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
      if (!visited[nx][ny] && arr[nx][ny] == 0) {
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 1) {
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
          if (visited[nx][ny] == 1) {
            arr[i][j] = 0;
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 1) {
        cnt += 1;
      }
    }
  }

  return cnt;
}

int main() {
  cin >> N >> M;
  int k;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> k;
      arr[i][j] = k;
      if (arr[i][j] == 1) {
        cnt += 1; 
      }
    }
  }
  int time = 0;
  while(true) {
     int tmp_cnt = bfs();
     time ++;
     if (tmp_cnt == 0) break;
     cnt = tmp_cnt;
  }

  cout << time << '\n';
  cout << cnt << '\n';
}
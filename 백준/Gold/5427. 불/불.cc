#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

char map[1004][1004];
int visited[1004][1004];
int visitedF[1004][1004];
int W, H;

queue<pair<int, int>> q;

void init() {
  for (int i = 0; i < 1004; i++) {
    for (int j = 0; j < 1004; j++) {
      visited[i][j] = -1;
      visitedF[i][j] = -1;
      map[i][j] = ' ';
    }
  }
}

void fireBfs(queue<pair<int, int>> q) {
  while (q.size()) {
    pair<int, int> tmp = q.front(); q.pop();
    int yy = tmp.first;
    int xx = tmp.second;
    for (int k = 0; k < 4; k++) {
      int ny = yy + dy[k];
      int nx = xx + dx[k];
      if (0 > ny || ny >= H || 0 > nx || nx >= W) {
        continue;
      }
      if (visitedF[ny][nx] != -1) continue;
      if (map[ny][nx] == '#') continue;
      visitedF[ny][nx] = visitedF[yy][xx] + 1;
      q.push({ny, nx});
      
    }
  }
}

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 0;

  while (q.size()) {
    pair<int, int> tmp = q.front(); q.pop();
    int yy = tmp.first;
    int xx = tmp.second;
    for (int k = 0; k < 4; k++) {
      int ny = yy + dy[k];
      int nx = xx + dx[k];
      if (0 > ny || ny >= H || 0 > nx || nx >= W) {
        cout << visited[yy][xx] + 1 << "\n";
        return;
      }
      if (map[ny][nx] == '#') continue;
      if (visitedF[ny][nx] != -1 && visitedF[ny][nx] <= visited[yy][xx] + 1) continue;
      if (visited[ny][nx] != -1) continue;
      visited[ny][nx] = visited[yy][xx] + 1;
      q.push({ny, nx});
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    init();
    int yy = -1, xx = -1;
    queue<pair<int, int>> q;
    cin >> W >> H;
    for (int y = 0; y < H; y++) {
      string s;
      cin >> s;
      for (int x = 0; x < W; x++) {
        map[y][x] = s[x];
        if (s[x] == '@') {
          yy = y; xx = x;
        }
        if (s[x] == '*') {
          q.push({y,x});
          visitedF[y][x] = 0;
        }
      }
    }
    if (q.size()) {
      fireBfs(q);
    }
    bfs(yy, xx);
  }
}
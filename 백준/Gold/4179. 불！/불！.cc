#include <iostream>
#include <queue>

using namespace std;

int fire[1004][1004];
int moving[1004][1004];
char map[1004][1004];
queue <pair<int, int>> que_j;
queue <pair<int, int>> que_f;
int R, C;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void input() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < C; j++) {
      map[i][j] = s[j];
      if (s[j] == 'J') {
        que_j.push({i,j});
        moving[i][j] = 0;
      }
      if (s[j] == 'F') {
        que_f.push({i,j});
        fire[i][j] = 0;
      }
    }
  }
}

int bfsPerson() {
  while (que_j.size()) {
    pair<int, int> temp = que_j.front(); que_j.pop();
    int y = temp.first;
    int x = temp.second;
    for (int k = 0; k < 4; k++) {
      int nx = dx[k] + x;
      int ny = dy[k] + y;
      if (0 > nx || nx >= C || 0 > ny || ny >= R) {
        return moving[y][x] + 1;
      }
      if (moving[ny][nx] >= 0 || map[ny][nx] == '#') continue;
      if (fire[ny][nx] != -1 && fire[ny][nx] <= moving[y][x] + 1) continue;
      moving[ny][nx] = moving[y][x] + 1;
      que_j.push({ny, nx});
    }
  }
  return -1;
}

void bfsFire() {
  while (que_f.size()) {
    pair<int, int> temp = que_f.front(); que_f.pop();
    int y = temp.first;
    int x = temp.second;
    for (int k = 0; k < 4; k++) {
      int nx = dx[k] + x;
      int ny = dy[k] + y;
      if (0 > nx || nx >= C || 0 > ny || ny >= R) {
        continue;
      }
      if (map[ny][nx] == '#'  || fire[ny][nx] >= 0) continue;
      que_f.push({ny, nx});
      fire[ny][nx] = fire[y][x] + 1;
    }
  }
}

void init() {
  for (int i = 0; i < 1004; i++) {
    for (int j = 0; j < 1004; j++) {
      moving[i][j] = -1;
      fire[i][j] = -1;
    }
  }
}

int main() {
  init();
  input();
  bfsFire();
  int ans = bfsPerson();
  if (ans == -1) {
    cout << "IMPOSSIBLE";
  } else {
    cout << ans;
  }
}
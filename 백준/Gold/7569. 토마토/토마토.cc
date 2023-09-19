#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

using T = tuple<int,int,int>;

vector<T> v = {{-1,0,0}, {1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
int M, N, H;
int map[104][104][104];
int visited[104][104][104];
queue<T> q;
int max_c = -1;

bool checking() {
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if(map[k][i][j] == 0) return false;
        if (max_c < visited[k][i][j]) {
          max_c = visited[k][i][j];
        }
      }
    }
  }
  return true;
}

void bfs() {
  while (q.size()) {
    T tmp = q.front(); q.pop();
    int m = get<0>(tmp);
    int n = get<1>(tmp);
    int h = get<2>(tmp);
    for (T k : v) {
      int y = m + get<0>(k);
      int x = n + get<1>(k);
      int hs = h + get<2>(k);
      if (0 > y || y >= N|| 0 > x || x >= M || 0 > hs || hs >= H) continue;
      if (map[hs][y][x] == -1) continue;
      if (map[hs][y][x] == 0 && visited[hs][y][x] == 0) {
        visited[hs][y][x] = visited[h][m][n] + 1;
        map[hs][y][x] = 1;
        q.push({y,x,hs});
      }
    }
  }
}

int main() {
  cin >> M >> N >> H;
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> map[k][i][j];
        if (map[k][i][j] == 1) {
          q.push({i,j,k});
          visited[k][i][j] = 1;
        }
      }
    }
  }

  if (checking()) {
    cout << "0";
    return 0;
  }
  bfs();
  if (!checking()) {
    cout << "-1";
  } else {
    cout << max_c - 1;
  }
}
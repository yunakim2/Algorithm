#include <iostream>
#include <queue>

using namespace std;

bool visited[504][504] = {false,};
int arr[504][504] = {0,};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;

int bfs(int y, int x) {
  visited[y][x] = true;
  queue <pair<int, int>> q;
  q.push(make_pair(y,x));
  int cnt = 1;
  while (q.size()) {
    auto &temp = q.front(); q.pop();
    int yy = temp.first;
    int xx = temp.second;
    for (int k = 0; k < 4; k++) {
      int ny = yy + dy[k];
      int nx = xx + dx[k];
      if (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (!visited[ny][nx] && arr[ny][nx] == 1) {
          visited[ny][nx] = true;
          q.push(make_pair(ny, nx));
          cnt += 1;
        }
      }
    }
    
  }
  return cnt;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int count = 0;
  int max_size = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1 && !visited[i][j]) {
        int cnt = bfs(i,j);
        count += 1;
        if (max_size < cnt) max_size = cnt;
      }
    }
  }
  cout << count << "\n" << max_size;
}
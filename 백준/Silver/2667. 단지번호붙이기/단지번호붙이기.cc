#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ans;
int arr[27][27];
int visited[27][27] = {0, };
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = 1;
  int cnt = 1;
  while (q.size()) {
    auto xy = q.front(); q.pop();
    int x = xy.first;
    int y = xy.second;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= N) {
        continue;
      }
      if (!visited[nx][ny] && arr[nx][ny] == 1) {
        visited[nx][ny] = 1;
        cnt += 1;
        q.push({nx, ny});
      }
    }
  }
  return cnt;
}
int main() {
  cin >> N;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && arr[i][j] == 1) {
        ans.push_back(bfs(i, j));
      }
    }
  }

  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << '\n';
  }
}
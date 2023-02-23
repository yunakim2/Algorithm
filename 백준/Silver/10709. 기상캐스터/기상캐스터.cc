#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
int H, W;
int arr[101][101];

void bfs() {

  while (q.size()) {
    auto xy = q.front(); q.pop();
    int x = xy.first;
    int y = xy.second;

    for (int i = y; i < W; i++) {
      if (arr[x][i] == 0) continue;
      if (arr[x][i] == -1) {
        arr[x][i] = i - y;
      } else {
        arr[x][i] = min(arr[x][i], i - y);
      }
    }
  }
}

int main() {
  cin >> H >> W;
  string s;
  for (int i = 0; i < H; i++) {
    cin >> s;
    for (int j = 0; j < W; j++) {
      if (s[j] == 'c') {
        arr[i][j] == 0;
        q.push({i, j});
      } else {
        arr[i][j] = -1;
      }
    }
  }

  bfs();

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }

}
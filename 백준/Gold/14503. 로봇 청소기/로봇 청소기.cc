#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[55][55];
int r, c, d;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main() {
  cin >> N >> M;
  cin >> r >> c >> d;
  int temp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> temp;
      arr[i][j] = temp;
    }
  }

  int ans = 0;

  while (true) {
   /* cout << "r " << r << " c " << c << " d " << d << endl;
    cout << "---" << endl;;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          cout << arr[i][j] << ' ';
        }
        cout << endl;
      }
    cout << "---" << endl;*/
    if (arr[r][c] == 0) {
      arr[r][c] = -1;
      ans += 1;
    }
    bool checkClean = false;
    for (int i = 0; i < 4; i++) {
      int nx = c + dx[i];
      int ny = r + dy[i];
      if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
      if (arr[ny][nx] == 0) {
        checkClean = true;
        break;
      }
    }

    if (checkClean) {
      if (d == 0) d = 3;
      else if (d == 3) d = 2;
      else if (d == 2) d = 1;
      else d = 0;

      int nx = c + dx[d];
      int ny = r + dy[d];
      if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
      if (arr[ny][nx] == 0) {
        r = ny;
        c = nx;
      }
    } else {
      int nx = c - dx[d];
      int ny = r - dy[d];
      if (nx < 0 || nx >= M || ny < 0 || ny >= N) break;
      if (arr[ny][nx] == 1) break;
      r = ny;
      c = nx;
    }
  }
  cout << ans;
}
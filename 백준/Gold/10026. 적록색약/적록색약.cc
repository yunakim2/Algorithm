#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

bool visited1[104][104];
bool visited2[104][104];
char map[104][104];

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int N;

void bfs(int y, int x, string s, bool isGreen) {

  if (isGreen) {
    visited1[y][x] = true;
  } else {
    visited2[y][x] = true;
  }
  queue<pair<int, int>> q;
  q.push({y, x});

  while (q.size()) {
    pair<int, int> tmp = q.front(); q.pop();
    int yy = tmp.first;
    int xx = tmp.second;
    for (int i = 0; i < 4; i++) {
      int ny = yy + dy[i];
      int nx = xx + dx[i];
      if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
      if (find(s.begin(), s.end(),map[ny][nx]) != s.end()) {
        if (isGreen) {
          if (!visited1[ny][nx]) {
            q.push({ny, nx});
            visited1[ny][nx] = true;
          }
        } else {
          if (!visited2[ny][nx]) {
            q.push({ny, nx});
            visited2[ny][nx] = true;
          }
        }
        
      }
    }
  }
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      map[i][j] = s[j];
    }
  }
  int count1 = 0;
  int count2 = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited1[i][j]) {
        string ss;
        if (map[i][j] == 'R') ss = "R";
        if (map[i][j] == 'B') ss = "B";
        if (map[i][j] == 'G') ss = "G";
        bfs(i,j, ss, true);
        count1 += 1;
      }

      if (!visited2[i][j]) {
        if (map[i][j] == 'R' || map[i][j] == 'G') {
          bfs(i,j, "RG", false);
        } else {
          bfs(i,j, "B", false);
        }
        count2 += 1;
      }
    }
  }
  cout << count1 << " " << count2;
}
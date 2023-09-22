#include <bits/stdc++.h>

using namespace std;
char maps[7][7];

int dy[] = {-1,0,0,1};
int dx[] = {0,1,-1,0};
vector<int> checking;


bool isOk(queue < pair<int, int> > q, int member[5][5], int visited[5][5]) {
  int count = 0;
  int correct = 0;
  while (q.size()) {
    int x, y;
    tie(x, y) = q.front(); q.pop();
    if (maps[x][y] == 'S') {
      count += 1;
    }
    correct += 1;
    for (int k = 0; k < 4; k++) {
      int yy = y + dy[k];
      int xx = x + dx[k];
      if (0 > yy || 0 > xx || yy >= 5 || xx >= 5) continue;
      if (visited[xx][yy]) continue;
      if (!member[xx][yy]) continue;
      q.push({xx, yy});
      visited[xx][yy] = true;
    }
  }
  if (correct >= 7 && count >= 4) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  for (int i = 0; i < 5; i++) {
    cin >> s;
    for (int j = 0; j < 5; j++) {
      maps[i][j] = s[j];
    }
  }

  int ans = 0;

  for (int i = 0; i < 25; i++) {
    if (i < 7) {
        checking.push_back(0);
    }
    else {
      checking.push_back(1);
    }
  }

  do {
    queue<pair<int, int>> q;
    int member[5][5] = {0, };
    int visited[5][5] = {0, };
    for (int i = 0; i < 25; i++) {
      if (checking[i] == 0) {
        member[i/5][i%5] = 1;
        if (q.empty()) {
          visited[i/5][i%5] = 1;
          q.push({i/5, i%5});
        }
       }
    }
    ans += (isOk(q, member, visited) == true);
  } while(next_permutation(checking.begin(), checking.end()));

  cout << ans;
  return 0;

}
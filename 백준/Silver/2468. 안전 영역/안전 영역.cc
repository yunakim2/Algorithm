#include <bits/stdc++.h>

using namespace std;
int N;
int arr[101][101];
int visited[101][101];
int safe_arr[101][101];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

vector<int> checking;
queue<pair<int, int>> q;

vector<string> split(string input, string delimiter) {
  vector<string> ans;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimiter)) != string::npos) {
    token = input.substr(0, pos);
    ans.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ans.push_back(input);
  return ans;
}

void init(int water) {
  while(!q.empty()) q.pop();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = 0;
      if (arr[i][j] > water) {
        safe_arr[i][j] = 1;
      } else {
        safe_arr[i][j] = 0;
      }
    }
  }
}

void bfs(int xx, int yy) {
  q.push({xx, yy});
  visited[xx][yy] = 1;

  while (!q.empty()) {
    auto nxy = q.front(); q.pop();
    int x = nxy.first;
    int y = nxy.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 > nx || nx >= N || 0 > ny || ny >= N) {
        continue;
      }
      if (safe_arr[nx][ny] == 1 && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }
}

int getMaxSafe(int water) {
  init(water);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (safe_arr[i][j] == 1 && !visited[i][j]) {
        bfs(i, j);
        cnt += 1;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> N;
  string s;
  getline(cin, s);
  for (int i = 0; i < N; i++) {
    getline(cin, s);
    vector<string> res = split(s, " ");
    for (int j = 0; j < N; j++) {
      arr[i][j] = stoi(res[j]);
      if (find(checking.begin(), checking.end(), stoi(res[j])) == checking.end()) {
        checking.push_back(stoi(res[j]));
      }
    }
  }
  int max_safe = 1;
  for (auto i : checking) {
    max_safe = max(max_safe, getMaxSafe(i));
  }
  cout << max_safe << '\n';
  return 0;
}
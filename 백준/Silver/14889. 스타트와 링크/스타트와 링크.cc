#include <bits/stdc++.h>

using namespace std;

int arr[22][22];
int N;
int visited[22];
int ans = 1000004;

int cal(vector<int> v) {
  int k = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (i == j) continue;
      k += arr[v[i]][v[j]];
    }
  }
  return k;
}

void dfs(int start, int cnt, int visit[]) {
  if (cnt == N/2) {
    vector<int> starts;
    vector<int> links;
    for (int i = 0; i < N; i++) {
      if (visit[i] == 1) {
        starts.push_back(i);
      } else {
        links.push_back(i);
      }
    }
    int cal_s = cal(starts);
    int cal_l = cal(links);
    ans = min(ans, abs(cal_s - cal_l));
  }
  for (int i = start; i < N; i++) {
    if (visit[i] == 1) continue;
    visit[i] = 1;
    dfs(i, cnt+1, visit);
    visit[i] = 0;
  }
}

int main() {
  cin >> N;
  int temp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> temp;
      arr[i][j] = temp;
    }
  }

  dfs(0, 0, visited);
  cout << ans;
}
#include <bits/stdc++.h>

using namespace std;
int K;
int N;
vector<int> arr[104];
int visited[104];

void dfs(int start) {
  for (int there : arr[start]) {
    if (!visited[there]) {
      visited[there] = 1;
      dfs(there);
    }
  }
  return;
}
int main() {
  cin >> K;
  cin >> N;

  int start, end;
  for (int i = 0; i < N; i++) {
    cin >> start >> end;
    arr[start].push_back(end);
    arr[end].push_back(start);
  }
  visited[1] = 1;
  dfs(1);
  int answer = 0;
  for (int i = 1; i <= K; i++) {
    if (i > 1 && visited[i]) {
      answer += 1;
    }
  }
  cout << answer;
}
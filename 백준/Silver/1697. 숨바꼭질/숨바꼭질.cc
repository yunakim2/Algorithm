#include <iostream>
#include <queue>
#include <string>

using namespace std;

int visited[100004];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  fill(visited, visited+100004, -1);
  if (N == K) {
    cout << "0";
    return 0;
  }
  queue<int> q;
  q.push(N);
  visited[N] = 0;

  while (q.size()) {
    int num= q.front(); q.pop();
    for (int k : {num -1, num +1, num * 2}) {
      if (k < 0 || k > 100000) continue;
      if (visited[k] != -1) continue;
      if (k == K) {
        cout << visited[num] + 1 << "\n";
        // cout << s + to_string(K);
        return 0;
      }
      q.push(k);
      visited[k] = visited[num] + 1;
    }
  }
  return 0;
}
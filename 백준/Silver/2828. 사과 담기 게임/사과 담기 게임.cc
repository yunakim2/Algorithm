#include <bits/stdc++.h>
using namespace std;
int N, M, J;
int arr[21];

int dfs(int start, pair<int, int> p, int move) {
  if (start == J) return move;
  if (p.first <= arr[start] && arr[start] < p.second) {
    return dfs(start + 1, p, move);
  }
  if (p.first > arr[start]) {
    int m = p.first - arr[start];
    return dfs(start + 1, {p.first - m, p.second - m}, move + m);
  }
  if (p.second <= arr[start]) {
    int m = arr[start] - p.second + 1;
    return dfs(start + 1, {p.first + m, p.second + m}, move + m);
  }
}

int main() {
  cin >> N >> M;
  cin >> J;
  int k;
  int cnt;
  for (int i = 0; i < J; i++) {
    cin >> k;
    arr[i] = k; 
  }
  cout << dfs(0, {1, 1+M}, 0) << '\n';
}
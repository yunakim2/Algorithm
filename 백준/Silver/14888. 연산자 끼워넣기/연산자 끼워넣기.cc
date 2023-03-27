#include <bits/stdc++.h>

using namespace std;

int mins = 1000000000;
int maxs = -1000000000;
int arr[13];
int N;

void dfs(int start, int sums, int plus, int minus, int mul, int div) {
  if (start == N-1) {
    mins = min(mins, sums);
    maxs = max(maxs, sums);
    return;
  }

  if (plus > 0) {
    dfs(start+1, sums + arr[start+1], plus-1, minus, mul, div);
  }
  if (minus > 0) {
    dfs(start+1, sums - arr[start+1], plus, minus-1, mul, div);
  }
  if (mul > 0) {
    dfs(start+1, sums * arr[start+1], plus, minus, mul-1, div);
  }
  if (div > 0) {
    dfs(start +1, sums / arr[start+1], plus, minus, mul, div-1);
  }
}


int main() {
  cin >> N;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    arr[i] = temp;
  }

  int plus = 0;
  int minus = 0;
  int div = 0;
  int mul = 0;
  cin >> plus >> minus >> mul >> div;

  dfs(0, arr[0], plus, minus, mul, div);
  cout << maxs << "\n" << mins;
}
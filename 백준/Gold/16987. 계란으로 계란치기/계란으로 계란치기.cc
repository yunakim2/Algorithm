#include <bits/stdc++.h>

using namespace std;

int S[9];
int W[9];
int N;
int max_egg = 0;

void go(int start) {
  if (start == N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] <= 0) count += 1;
    }
    max_egg = max(max_egg, count);
    return;
  }
  
  if (S[start] <= 0) {
    return go(start + 1);
  }

  bool checking = false;
  for (int i = 0; i < N; i++) {
    if (i == start) continue;
    if (S[i] > 0) {
      checking = true;
      S[start] -= W[i];
      S[i] -= W[start];
      go(start+1);
      S[start] += W[i];
      S[i] += W[start];
    }
  }
  if (!checking) {
    go(start+1);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> W[i];
  }
  go(0);
  cout << max_egg;
}
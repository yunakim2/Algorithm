#include <iostream>

using namespace std;

int N;
bool isused1[40];
bool isused2[40];
bool isused3[40];
int cnt;

void go(int start) {
  if (start == N) {
    cnt += 1;
    return;
  }
  for (int i = 0; i < N; i++) {
    if (isused1[i] || isused2[i + start] || isused3[start - i + N - 1]) {
      continue;
    }
    isused1[i] = 1;
    isused2[i + start] = 1;
    isused3[start - i + N -1] = 1;
    go(start + 1);
    isused1[i] = 0;
    isused2[i + start] = 0;
    isused3[start - i + N -1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  go(0);
  cout << cnt;
}

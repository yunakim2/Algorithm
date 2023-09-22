#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];

int N, M;

void go(int start, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << arr[i] + 1 << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = start; i < N; i++) {
      arr[cnt] = i;
      go(i, cnt + 1);
  }
}

int main() {
  cin >> N >> M;
  go(0, 0);
}
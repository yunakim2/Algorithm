#include <iostream>

using namespace std;

int N, S;
int ans;
int arr[23];

void go(int i, int sum) {
  if (i== N) {
    if (sum == S) {
      ans += 1;
    }
    return;
  }

  go(i+1, sum + arr[i]);
  go(i+1, sum);
}

int main() {
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  go(0, 0);
  if (S == 0) ans --;
  cout << ans;
}
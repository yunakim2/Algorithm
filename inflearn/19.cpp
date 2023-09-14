#include <iostream>

using namespace std;

int arr[102];

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < N-1; i++) {
    bool checking = true;
    for (int j = i+1; j < N; j++) {
      if (arr[i] <= arr[j]) {
        checking = false;
        break;
      }
    }
    if (checking) {
      ans += 1;
    }
  }
  cout << ans;
}
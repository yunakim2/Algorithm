#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int count = 0;
  int max = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (num > M) {
      count += 1;
    } else {
      if (count != 0) {
        if (count > max) {
          max = count;
        }
        count = 0;
      }
    }
    if (i == N - 1) {
      if (count != 0 && max == 0) {
       max = count;
      }
      if (max < count) {
        max = count;
      }
    }
  }
  
  if (max == 0) cout << -1;
  else cout << max;
}
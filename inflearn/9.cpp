#include <iostream>

using namespace std;

int arr[50004] = {0,};

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j = j + i) {
      if (j % i == 0) arr[j] += 1;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << arr[i] << " ";
  }
}

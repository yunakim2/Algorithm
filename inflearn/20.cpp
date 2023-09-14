#include <iostream>

using namespace std;

int arr[2][104];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    if (arr[0][i] == 1 && arr[1][i] == 3) {
      cout << "A" << "\n";
      continue;
    }
    if (arr[0][i] == 2 && arr[1][i] == 1) {
      cout << "A" << "\n";
      continue;
    }
    if (arr[0][i] == 3 && arr[1][i] == 2) {
      cout << "A" << "\n";
      continue;
    }
    if (arr[1][i] == 1 && arr[0][i] == 3) {
      cout << "B" << "\n";
      continue;
    }
    if (arr[1][i] == 2 && arr[0][i] == 1) {
      cout << "B" << "\n";
      continue;
    }
    if (arr[1][i] == 3 && arr[0][i] == 2) {
      cout << "B" << "\n";
      continue;
    }
    cout << "D" << "\n";
  }
}
#include <iostream>

using namespace std;

int arr[2][10];

int main() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> arr[i][j];
    }
  }

  int A = 0, B = 0;
  string last_winner = "";
  for (int i = 0; i < 10; i++) {
    if (arr[0][i] > arr[1][i]) {
      A += 3;
      last_winner = "A";
    } else if (arr[0][i] < arr[1][i]) {
      B += 3;
      last_winner = "B";
    } else {
      A += 1;
      B += 1;
    }
  }
  cout << A << " " << B << "\n";
  if (A == B) {
    if (last_winner != "") {
      cout << last_winner;
    } else {
      cout << "D";
    }
  } else if (A > B) {
    cout << "A";
  } else {
    cout << "B";
  }
}
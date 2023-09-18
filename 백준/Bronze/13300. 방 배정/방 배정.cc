#include <iostream>

using namespace std;

int arr[6][2] = {0,};

int main() {
  int num, K;
  cin >> num >> K;
  for (int i = 0; i < num; i++) {
    int gender, grade;
    cin >> gender >> grade;
    arr[grade-1][gender] += 1;
  }
  int room = 0;
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 2; k++) {
      if (arr[i][k] == 0) continue;
      if (arr[i][k] / K < 1) room += 1;
      else {
        if (arr[i][k] % K == 0) room += int(arr[i][k] / K);
        else {
          room += int(arr[i][k]/K) + 1;
        }
      }
    }
  }
  cout << room;
}
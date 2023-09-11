#include <iostream>

using namespace std;

int arr[104];

int main() {
  int n, max = 0, min = 100000004;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (max < arr[i]) max = arr[i];
    if (min > arr[i]) min = arr[i];
  }
  cout << max - min;
}
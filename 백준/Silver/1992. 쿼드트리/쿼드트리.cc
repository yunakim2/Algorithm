#include <bits/stdc++.h>
using namespace std;

int N;
int arr[65][65];
string quadTree(int x, int y, int size) {
  if (size == 1) return to_string(arr[x][y]);
  int startData = arr[x][y];
  bool isCompress = true;
  string ret;
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (startData != arr[i][j]) {
         ret += '(';
         ret += quadTree(x, y, size/2);
         ret += quadTree(x, y + size/2, size/2);
         ret += quadTree(x + size/2, y, size/2);
         ret += quadTree(x + size/2, y + size/2, size/2);
         ret += ')';
         return ret;
      }
    }
  }
  return to_string(arr[x][y]);
}

int main() {
  cin >> N;
  string s;
  getline(cin, s);
  for (int i = 0; i < N; i++) {
    getline(cin, s);
    for (int j = 0 ; j < N; j++) {
      arr[i][j] = s[j] - '0';
    }
  }
  cout << quadTree(0, 0, N) << '\n';
}
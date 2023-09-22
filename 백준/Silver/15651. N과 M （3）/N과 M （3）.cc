#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
int arr[10];

void go(int start, int count) {
  if (count == M) {
    for (int i = 0; i < M; i++) {
      cout <<  arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= N; i++) {
    arr[start] = i;
    go(start + 1, count + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  
  go(0,0);
}
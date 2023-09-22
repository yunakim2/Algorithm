#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checking[10];
vector <int> number;
int N, M;

void go(int start, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << number[checking[i]] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    checking[start] = i;
    go(start + 1, cnt + 1);
  }
}

int main() {

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    number.push_back(num);
  }
  sort(number.begin(), number.end());
  go(0, 0);
  return 0;
}
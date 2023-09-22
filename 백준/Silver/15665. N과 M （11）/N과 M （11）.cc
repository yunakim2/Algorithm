#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


int checking[10];
int visited[10];
vector <int> number;
int N, M;

set<string> s;

void go(int start, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << number[checking[i]] << " ";
    }
    cout << "\n";
    return;
  }
  int tmp = 0;
  for (int i = 0; i < N; i++) {
    if (number[i] != tmp) {
      checking[cnt] = i;
      tmp = number[i];
      go(i, cnt + 1); // 내가 고른 i 보다 커야함
    }
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
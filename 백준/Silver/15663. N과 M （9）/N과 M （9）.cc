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
    if (!visited[i] && number[i] != tmp) {
      visited[i] = 1;
      checking[start] = i;
      tmp = number[i];
      go(start + 1, cnt + 1);
      visited[i] = 0;
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
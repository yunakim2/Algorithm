#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10];
int check[10];
vector <int> number;
int N, M;


void go(int start, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << number[visited[i]] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (check[i]) continue;
    check[i] = 1;
    visited[start] = i;
    go(start+1, cnt +1);
    check[i] = 0;
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

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> checking;
vector <int> number;
int N, M;


int main() {

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    number.push_back(num);
  }

  for (int i = 0; i < N; i++) {
    if (i < M) {
      checking.push_back(0);
    } else {
      checking.push_back(1);
    }
  }
  sort(number.begin(), number.end());

  do {
    for (int i = 0; i < N; i++) {
      if (checking[i] == 0) {
        cout << number[i] << " ";
      }
    }
    cout << "\n";
  } while(next_permutation(checking.begin(), checking.end()));
  return 0;
}
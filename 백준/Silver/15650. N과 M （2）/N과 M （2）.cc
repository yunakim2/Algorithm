#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main() {

  int N, K;
  cin >> N >> K;


  for (int i = 0; i < K; i++) {
    v.push_back(0);
  }

  for (int i = 0; i < N-K; i++) {
    v.push_back(1);
  }

  do {
    for (int i = 0; i < N; i++) {
      if (v[i] == 0) {
        cout << i+1 << " ";
      }
    }
    cout << "\n";
  } while(
    next_permutation(v.begin(), v.end())
  );
}
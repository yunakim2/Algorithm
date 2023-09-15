#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[104];
vector <int> v;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  v.push_back(0);
  for (int i = 0; i < N - 1; i++) {
    v.push_back(abs(arr[i] - arr[i+1]));
  }
  
  sort(v.begin(), v.end());
  bool checking = true;
  for (int i = 1; i <= N - 1; i++) {
    if (v[i] != i) {
      checking = false;
      break;
    }
  }
  if (checking) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
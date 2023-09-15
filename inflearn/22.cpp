#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100004];

int main() {
  int N, K;
  cin >> N >> K;
  int sum = 0;
  int sum_arr[100004];
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sum += arr[i];
    sum_arr[i] = sum;
  }
  // 이중 for문은 시간 초과가 발생함
  //vector <int> v;
  //for (int i = 0; i <= N-K; i++) {
  //  int cnt = 0;
  //  for (int j = i; j <= i + K-1; j++) {
  //    cnt += arr[j];
  //  }
  //  v.push_back(cnt);
  //}
  //sort(v.begin(), v.end());
  //cout << v.back();
  int max = 0;
  for (int i = 0; i< N; i++) {
    int sums = sum_arr[i+K-1] - sum_arr[i];
    if (sums> max) {
      max = sums;
    }
  }
  cout << max;
}
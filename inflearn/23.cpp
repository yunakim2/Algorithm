#include <iostream>

using namespace std;

int main() {
  int N, re, cnt = 0, max = 0; 
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num = 0;
    cin >> num;
    if (i == 0) {
      re = num;
      cnt = 1;
    }
    else {
      if (re <= num) {
        cnt += 1;
      } else {
        cnt = 1;
      }
    }
    if (max < cnt) max = cnt;
    re = num;
  }
  cout << max;
}
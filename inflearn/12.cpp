#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
  cin >> N;
  int cnt = 0;
  int pow = 1;
  int sum = 0;
  for (int i = 9; sum+i < N; i = i*10) {
    if (N >= i) {
      cnt += (i * pow);
    }
    sum += i;
    pow += 1;
  }
  cnt += ((N - sum) * pow);
  cout << cnt;
}
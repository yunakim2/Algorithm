#include <iostream>
#include <string>

using namespace std;

int N;
int arr[10] = {0,};

int main() {
  cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    string s = to_string(i);
    for (int k = 0; k < s.length(); k++) {
      cnt += 1;
    }
  }
  cout << cnt;
}
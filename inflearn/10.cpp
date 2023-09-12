#include <iostream>
#include <string>

using namespace std;

int digit_sum(int x) {
  string s = to_string(x);
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    cnt += s[i] - '0';
  }
  return cnt;
}

int main() {
  int n, num, max_num = 0, max = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    int cnts = digit_sum(num);
    if (max <= cnts) {
      if (max == cnts) {
        if (max_num < num) {
          max_num = num;
          max = cnts;
        }
        continue;
      }
      max_num = num;
      max = cnts;
      continue;
    }
  }
  cout << max_num;
}
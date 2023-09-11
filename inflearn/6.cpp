#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, ans;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (isdigit(s[i])) {
      ans += s[i];
    }
  }
  int num = stoi(ans);
  int cnt = 0;
  for (int i = 1; i <= num; i++) {
    if(num % i == 0) cnt += 1;
  }
  cout << num << "\n";
  cout << cnt;
}
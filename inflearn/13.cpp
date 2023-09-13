#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int arr[10] = {0,};
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    arr[s[i]-'0'] += 1;
  }
  int max = 0;
  int max_i = 0;
  for (int i = 1; i < 10; i++) {
    if (max <= arr[i]) {
      max_i = i;
      max = arr[i];
    }
  }
  cout << max_i;
}
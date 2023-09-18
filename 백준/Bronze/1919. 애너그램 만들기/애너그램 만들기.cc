#include <iostream>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;


  int arr1[26] = {0, };
  int arr2[26] = {0, };

  for (int i = 0; i < s1.size(); i++) {
    arr1[s1[i] - 'a'] += 1;
  }

  for (int j = 0; j < s2.size(); j++) {
    arr2[s2[j] - 'a'] += 1;
  }

  int cnt = 0;
  for (int k = 0; k < 26; k++) {
    if (arr1[k] != arr2[k]) {
      cnt += abs(arr1[k] - arr2[k]);
    }
  }
  cout << cnt;
}
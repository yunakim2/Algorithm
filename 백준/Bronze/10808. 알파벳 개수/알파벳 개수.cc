#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int a[26] = {0,};
  for (auto alpha : s) {
    a[alpha-'a'] += 1;
  }
  for (int i : a) {
    cout << i << ' ';
  }
}
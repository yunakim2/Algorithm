#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string arr[100004];
  map<string, int> name_map2;
  string temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    arr[i] = temp;
    name_map2[temp] = i;
  }
  for (int j = 0; j < k; j++) {
    cin >> temp;
    if (atoi(temp.c_str()) == 0) {
      cout << name_map2[temp] << '\n';
    } else {
      cout << arr[atoi(temp.c_str())] << '\n';
    }
  }

  return 0;
}
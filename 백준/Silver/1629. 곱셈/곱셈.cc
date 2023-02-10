#include <bits/stdc++.h>

using namespace std;
long long A, B, C;
long long go(long long a, long long b) {
  if (b == 1) return a % C;
  long long ret = go(a, b/2);
  ret = (ret * ret) % C;
  if (b % 2) ret = (ret * a) % C;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> A >> B >> C;
  cout << go(A, B) << '\n';
  return 0;
}
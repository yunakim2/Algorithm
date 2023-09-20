#include <iostream>

using namespace std;

int ans;
long long A, B, C;

long long cal(int a, int cnt) {
  if (cnt == 1) return a % C;
  long long ret = cal(a, cnt/2);
  ret = ret * ret % C;
  if (cnt % 2 == 0) return ret;
  return ret * a % C;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;
  cout << cal(A, B);
}
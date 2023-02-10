#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string str;
  cin >> str;
  int cnt[200] = {0,};
  string ret = "";
  
  for (auto ch : str) {
    cnt[ch] ++;
  }
  char mid = ' ';
  int flag = 0;
  for (int i = 'Z'; i >= 'A'; i--) {
    if (cnt[i]) {
      if (cnt[i] & 1) {
        mid = char(i); // 홀수는 중앙에 넣어야 되기 때문
        flag ++;
        cnt[i] --;
      }
      if (flag == 2) break;
      for (int j = 0; j < cnt[i]; j += 2) {
        ret = char(i) + ret;
        ret += char(i);
      }
    }
  }
  if (mid != ' ') ret.insert(ret.begin() + ret.size() / 2, mid);
  if (flag == 2) cout << "I'm Sorry Hansoo\n";
  else cout << ret << '\n';
  return 0;
}
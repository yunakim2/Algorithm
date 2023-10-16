#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <string>

using namespace std;


int main() {
  int N;
  cin >> N;
  int str = 0, ball = 0;
  string num;
  vector<tuple<string, int, int>> v;
  
  for (int i = 0; i < N; i++) {
    cin >> num >> str >> ball;
    v.push_back({num, str, ball});
  }
  int ans = 0;
  string tmp = "";
  int c_str = 0, c_ball = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = 1; k <= 9; k++) {
        if (i == j || i == k || j == k) continue;
        tmp = "";
        tmp += to_string(i) + to_string(j) + to_string(k);
        bool isSuccess= true;
        for (int vv = 0; vv < v.size(); vv++) {
          tie(num, str, ball) = v[vv];
          c_str = 0;
          c_ball = 0;
          for (int m = 0; m < 3; m++) {
            if (num.find(tmp[m]) != string::npos) {
              if (num[m] == tmp[m]) {
                c_str ++;
              } else {
                c_ball ++;
              }
            }
          }
          if (c_ball != ball || c_str != str) {
            isSuccess = false;
            break;
          }
        }
        if (isSuccess) {
          ans ++;
        }
      }
    }
  }
  cout << ans;

}
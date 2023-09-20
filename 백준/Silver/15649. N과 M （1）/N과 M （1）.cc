#include <iostream>
#include <string>

using namespace std;

int checking[9];
int M, N;

void go(int cnt, string s) {
  if (cnt == 0) {
    cout << s << "\n";
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (!checking[i]) {
      checking[i] = true;
      if (s == "") {
        go(cnt -1, to_string(i));
      } else {
        go(cnt-1, s + " " + to_string(i));
      }
      checking[i] = false;
    }
  }

}

int main() {
  cin >> N >> M;
  go(M, "");
}
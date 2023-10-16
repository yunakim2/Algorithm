#include <iostream>
#include <set>

using namespace std;


int main() {
  int N;
  cin >> N;
  int cnt = 0;
  for (int A = 1; A <= N - 2; A++) {
    for (int B = 1; B <= N - 2; B++) {
      for (int C = 1; C <= N - 2; C++) {
        if ((A + B + C) == N) {
          if (A % 2 == 0) {
            if ((C - B) >= 2) {
              cnt ++;
             }
           }
        }
      }
    }
  }
  cout << cnt;
}
#include <iostream>

using namespace std;

int getSum(int n) {
  return (n * (n+1)) / 2;
}

int main() {
  int student;
  cin >> student;
  
  for (int i = 0; i < student; i++) {
    int num, ans;
    cin >> num >> ans;
    if (getSum(num) == ans) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
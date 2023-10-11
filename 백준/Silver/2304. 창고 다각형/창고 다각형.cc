#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
int arr[1004];

int main() {
  cin >> N;
  vector<int> row;

  int kk, h;
  int max_h = 0;
  for (int i = 0; i < N; i++) {
    cin >> kk >> h;
    arr[kk] = h;
    row.push_back(kk);
    max_h = max(h, max_h);
  }

  sort(row.begin(), row.end());
  int max_size = (row.back() + 1 - row.front()) * max_h;
  int ans = 0;
  //cout << max_size << "\n";

  int width = 0, height = arr[row.front()];
  for (int i = row.front(); i <= row.back(); i++) {
    if (height < arr[i]) {
      //cout << width << ", " << max_h-height << "**\n";
      max_size -= (width * (max_h - height));
      height = arr[i];
      width = 1;
      //cout << height << "\n";
      if (height == max_h) break;
      continue;
    }
    width++;
  }

  //cout << max_size << "\n";

  width = 0; height = arr[row.back()];
  for (int i = row.back(); i >= row.front(); i--) {
    if (height < arr[i]) {
      //cout << width << ", " << max_h-height << "**\n";
      max_size -= (width * (max_h - height));
      height = arr[i];
      width = 1;
      //cout << height << "\n";
      if (height == max_h) break;
      continue;
    }
    width++;
  }
  cout << max_size << "\n";

}
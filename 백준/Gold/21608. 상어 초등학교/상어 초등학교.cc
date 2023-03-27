#include <bits/stdc++.h>

using namespace std;
int arr[22][22];
int N;
vector<int> v[404];
vector<int> stu_list;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}

void setArray() {
  for (int i = 0; i < stu_list.size(); i++) {
    int x, y;
    int max_x = 0, max_y = 0;
    int max_fav = -1;
    int max_empty = -1;
    for (y = 0; y < N; y++) {
      for (x = 0; x < N; x++) {
        if (arr[y][x] != 0) continue;
        int fav = 0;
        int empty = 0;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if (arr[ny][nx] == 0) empty += 1;
          if (find(v[stu_list[i]].begin(), v[stu_list[i]].end(), arr[ny][nx]) != v[stu_list[i]].end()) fav += 1;
        }
        //cout << "max_fav : " << max_fav << " max_empty : " << max_empty << "\n";
        //cout << "xx: " << x << " yy: " << y << " empty :" << empty << " fav :" << fav << "\n";
        if (max_fav < fav) {
          max_y = y;
          max_x = x;
          max_fav = fav;
          max_empty = empty;
        }

        if (max_fav == fav) {
          if (max_empty < empty) {
          //cout << "333\n";
            max_y = y;
            max_x = x;
            max_fav = fav;
            max_empty = empty;
          }
          if (max_empty == empty) {
            if (max_y > y) {
              max_y = y;
              max_x = x;
              max_fav = fav;
              max_empty = empty;
            }
          }
        }
        }
      }
    //cout << "x: " << max_x << "y:" << max_y <<"\n";
    arr[max_y][max_x] = stu_list[i];
    //print();
    //cout << "**********************************\n";
  }
}

int main() {
  cin >> N;
  int stu, tmp1, tmp2, tmp3, tmp4;
  for (int i = 0; i < N*N; i++) {
    cin >> stu >> tmp1 >> tmp2 >> tmp3 >> tmp4;
    v[stu].push_back(tmp1);
    v[stu].push_back(tmp2);
    v[stu].push_back(tmp3);
    v[stu].push_back(tmp4);
    stu_list.push_back(stu);
  }

  setArray();
  int total_ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int check = arr[i][j];
      int ans = 0;
      for (int k = 0; k < 4; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
        if (find(v[check].begin(), v[check].end(), arr[ny][nx]) != v[check].end()) ans += 1;
      }
      if (ans > 1) {
        total_ans += pow(10, (ans-1));
      } else {
        total_ans += ans;
      }
    }
  }
  cout << total_ans;
}
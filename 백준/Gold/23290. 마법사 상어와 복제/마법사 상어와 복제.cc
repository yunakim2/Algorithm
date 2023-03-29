#include <bits/stdc++.h>

using namespace std;
int N = 4;
int S, M;
int f_dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int f_dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int s_dy[] = {0, -1, 0, 1};
int s_dx[] = {-1, 0, 1, 0};
struct fish {
    int x, y, d;
};
struct shark {
    int x, y;
};
vector<fish> f;
shark sh;
int arr[5][5];
vector<fish> r_f;
int sm[5][5];

void printArray() {
    cout << "------------------\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
}

void moveFish() {
    int new_arr[5][5] = {0,};
    for(int i = 0; i < f.size(); i++) {
        int dd = f[i].d;
        int xx = f[i].x;
        int yy = f[i].y;
        //cout << "xx : " << xx << " yy : " << yy << " dd : " << dd << "\n";
        while (true) {
            int tx = xx + f_dx[dd];
            int ty = yy + f_dy[dd];
            if (0 > tx || tx >= N || 0 > ty || ty >= N) {
                if (dd == 0) {
                  dd = 7;
                } else {
                  dd -= 1;
                }
                
                if (dd == f[i].d) {
                  break;
                }
                continue;
            }
            if (sm[tx][ty] < 0) {
                if (dd == 0) {
                  dd = 7;
                } else {
                  dd -= 1;
                }
                if (dd == f[i].d) {
                  break;
                }
                continue;
            }
            if (tx == sh.x && ty == sh.y) {
                //cout << "kkkdfaljdf\n";
                if (dd == 0) {
                  dd = 7;
                } else {
                  dd -= 1;
                }
                if (dd == f[i].d) {
                  break;
                }
                continue;
            }
            f[i].x = tx;
            f[i].y = ty;
            f[i].d = dd;
            break;
            }
        //cout << "*** xx : " << f[i].x << " yy : " << f[i].y << " dd : " << f[i].d << "\n";
        //cout << "--";
        //printArray();
        new_arr[f[i].x][f[i].y] += 1;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        arr[i][j] = new_arr[i][j];
      }
    }
}

void moveShark() {
    int max_fish = -100000;
    int max_x = sh.x, max_y = sh.y;
    vector<pair <int, int> > shark_move;
    int visited[5][5] = {0, };
    //cout << "sh.x :" << sh.x << " sh.y " << sh.y << "\n";
    for(int i = 0; i < N; i++) {
        int x1 = sh.x + s_dx[i];
        int y1 = sh.y + s_dy[i];
        if (0 > x1 || x1 >= N || 0 > y1 || y1 >= N) continue;
        for(int j = 0; j < N; j++) {
            //if (i > j) {
            //  if (i-2 == j) continue;
            //} else {
            //  if (j-2 == i) continue;
            //}
            int x2 = x1 + s_dx[j];
            int y2 = y1 + s_dy[j];
            if (0 > x2 || x2 >= N || 0 > y2 || y2 >= N) continue;
            for(int k = 0; k <N; k++) {
            //if (j > k) {
            //  if (j-2 == k) continue;
            //} else {
            //  if (k-2 == j) continue;
            //}   
            int x3 = x2 + s_dx[k];
            int y3 = y2 + s_dy[k];
            if (0 > x3 || x3 >= N || 0 > y3 || y3 >= N) continue;
            vector< pair<int, int> > temp_move;
            temp_move.push_back({x1, y1});
            temp_move.push_back({x2, y2});
            temp_move.push_back({x3, y3});
            int fish = arr[x1][y1];
            visited[x1][y1] = 1;
            if (visited[x2][y2] == 0) {
              fish += arr[x2][y2];
            }
            visited[x2][y2];
            if (visited[x3][y3] == 0) {
              fish += arr[x3][y3];
            }
            //cout << fish << "[]][[][] " << i << j << k << "\n";
            /*cout << "----------------------";
            cout << x1 << y1 << "\n";
            cout << x2 << y2 << "\n";
            cout << x3 << y3 << "\n";
            cout << "----------------------";*/
            if (max_fish < fish) {
                //cout << "max ::" << i << j << k << "\n";
                max_x = x3;
                max_y = y3;
                max_fish = fish;
                shark_move.clear();
                shark_move.shrink_to_fit();
                shark_move = temp_move;
            }
            }
        }
    }

    for(int i = 0; i < shark_move.size(); i++) {
        int xx = shark_move[i].first;
        int yy = shark_move[i].second;
        if (arr[xx][yy] > 0) {
          f.erase(remove_if(f.begin(), f.end(), [&](fish ff) {
            if(ff.x == xx && ff.y == yy) return true;
            return false;
           }), f.end());
          sm[xx][yy] = -1;
          arr[xx][yy] = 0;
          shark se;
          se.x = xx;
          se.y = yy;
        }
    }
    sh.x = max_x;
    sh.y = max_y;
    //cout << " kkdfalfj ::: " << sh.x << sh.y << "\n";

}

void setArray() {
    for(int i = 0; i < f.size(); i++) {
        int x = f[i].x;
        int y = f[i].y;
        arr[x][y] += 1;
    }
}

void removeFishSmell() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (sm[i][j] < 0) sm[i][j]--;
      if (sm[i][j] == -4) {
        sm[i][j] = 0;
      }
    }
  }
}

int main() {
    cin >> M >> S;
    int tx, ty, td;
    for(int i = 0; i < M; i++) {
        cin >> tx >> ty >> td;
        fish tf;
        tf.x = tx-1;
        tf.y = ty-1;
        tf.d = td-1;
        arr[tf.x][tf.y] += 1;
        f.push_back(tf);
    }
    cin >> tx >> ty;
    sh.x = tx-1;
    sh.y = ty-1;
    while(S) {
        r_f.clear();
        r_f.shrink_to_fit();
        r_f = f;
        //for (int i = 0; i < f.size(); i++) {
        //  cout << f[i].x << f[i].y << "ll\n";
        //}
        //cout << "S :: " << S << "\n";
        //printArray();
        moveFish();
        //cout << "moveFish" << "\n";
        //printArray();
        moveShark();
        //cout << "moveShark" << "\n";
        //printArray();
        removeFishSmell();
        //for (int i = 0; i < r_f.size(); i++) {
        //  cout << r_f[i].x << r_f[i].y << "kk\n";
        //}
        for(int i = 0; i < r_f.size(); i++) {
            arr[r_f[i].x][r_f[i].y] += 1;
            f.push_back(r_f[i]);
        }
        //cout << "copy fish\n";
        //printArray();
        S-=1;
        //cout << "shx : " << sh.x << "shy : " << sh.y << "\n";
        //cout << "smells ----\n";
        //for (int i = 0; i < N; i++) {
        //  for (int j = 0; j < N; j++) {
        //    cout << sm[i][j] << " ";
        //  }
        //  cout << "\n";
        //}
    }
    int total_fish = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (arr[i][j] != -1) {
                total_fish += arr[i][j];
            }
        }
    }

    cout << total_fish;
}
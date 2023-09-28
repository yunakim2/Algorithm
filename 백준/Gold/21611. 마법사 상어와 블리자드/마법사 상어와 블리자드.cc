#include <bits/stdc++.h>

using namespace std;


// 1. 상어 , d 방향으로 거리가 s 이하인 모든 칸 파괴- > 파괴된 칸 빈칸 됨 (벽은 파괴X)
// 2. 구슬 이동 (어떤 칸 A 번호보다 번호가 하나 작은 칸이 빈칸이면, A에 있는 구슬은 그 빈칸으로 이동함) 
// 더이상 구슬이 이동하지 않을 때까지 반복
// 3. 구슬 폭발 - 4개 이상 연속하는 구슬 있을 때 빨생 
// 4. 구슬 이동
// -> 구슬이 없을 때까지 반복
// 5. 구슬 변화 -> 연속 하는 구슬 하나의 그룹 
// 6. 하나의 그룹은 두개의 구슬 A, B로 변한다 A는 그룹에 들어있는 구슬의 개수 / B는 그룹을 이루고 있는 구슬의 번호

int board[55][55];
int N;
int M;
int ans;
vector<pair<int, int>> v;
int dy[] = {-1, +1, 0, 0};
int dx[] = {0, 0, -1, +1};
int step = 1;
struct sh {
  int x, y;
};

sh shark;

int bomb1, bomb2, bomb3;

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i+1][j+1];
    }
  }

  v.push_back({0, 0});
  for (int i = 0; i < M; i++) {
    int d, s;
    cin >> d >> s;
    v.push_back({d-1, s});
  }
  shark.x = (N+1)/2;
  shark.y = (N+1)/2;
}

void removeBoard() {
  int ny, nx;
  int d = v[step].first;
  for (int i = 1; i <= v[step].second; i++) {
    ny = dy[d]*i + shark.y;
    nx = dx[d]*i + shark.x;
    if (1 > ny || ny > N || 1 > nx || nx > N) continue;
    board[ny][nx] = 0;
  }
}

void printBoard() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // cout << board[i+1][j+1] << " ";
    }
    // cout << "\n";
  }
}

vector<int> getBoardList() {
  vector<int> tmp;
  int d1, d2;
  int sx = 1, sy = 1;
  if (board[sy][sx] != 0) {
    tmp.push_back(board[sy][sx]);
  }
  for (int k = N-1; k >= 1; k--) {
    if (k % 2 == 0) {
      d1 = 1;
      d2 = 2;
    } else {
      d1 = 0;
      d2 = 3;
    }
    if (k == N - 1) {
      for (int j = 1; j <= k; j++) {
          sy += dy[3];
          sx += dx[3];
          //// cout << sy << " " << sx << "\n";
        if (board[sy][sx] != 0) {
          tmp.push_back(board[sy][sx]);
        }
      }
    }
    for (int j = 1; j <= k; j++) {
      sy += dy[d1];
      sx += dx[d1];
      //// cout << sy << " " << sx << "\n";
      if (board[sy][sx] != 0) {
        tmp.push_back(board[sy][sx]);
      }
    }
    
    if (k != 1) {
      for (int j = 1; j <= k; j++) {
        sy += dy[d2];
        sx += dx[d2];
        //// cout << sy << " " << sx << "\n";
        if (board[sy][sx] != 0) {
          tmp.push_back(board[sy][sx]);
        }
      }
    }
    
    
  }
  // cout << "getBoard \n";
  for (int k = tmp.size() - 1; k >= 0; k--) {
    // cout << tmp[k] << " ";
  }
  // cout << "\n";
  return tmp;
}

void moveBoard() {
  vector<int> lists = getBoardList();
  
}

vector<int> bombBoard() {
  queue<int> q;
  vector<int> tmp = getBoardList();
  bool isBomb = false;
 for (int k = tmp.size() - 1; k >= 0; k--) {
        q.push(tmp[k]);
  }
  while (true) {
    int cnt, checking;
    tmp.clear();
    tmp.shrink_to_fit();
    isBomb = false;
    while (q.size()) {
        cnt = 1;
        checking = q.front();
        q.pop();
         // cout << " checking - " << checking << "\n";
        while (q.size() && checking == q.front()) {
          q.pop();
          cnt += 1;
        }
         // cout << "cnt - " << cnt << "\n";
        
        if (cnt < 4) {
          for (int k = 0; k < cnt; k++) {
            tmp.push_back(checking);
          }
        } else {
          isBomb = true;
          if (checking == 1) {
            bomb1 += cnt;
          } else if (checking == 2) {
            bomb2 += cnt;
          } else {
            bomb3 += cnt;
          }
        }
    }
    // cout << "** ";
    for (int i = 0; i < tmp.size(); i++) {
      // cout << tmp[i] << " ";
      q.push(tmp[i]);
    }
    // cout << "\n";
    if (!isBomb) break; 
    }
  return tmp;
}

void setBoard(vector<int> tmp) {
  int new_board[55][55] = {0,};
  queue<int> q;
  for (int i = 0; i < tmp.size(); i++) {
    q.push(tmp[i]);
  }
  vector<int> new_list;
  int cnt, checking;
  while (q.size()) {
    cnt = 1;
    checking = q.front();
    q.pop();
    while (q.size() && checking == q.front()) {
      q.pop();
      cnt += 1;
    }
    new_list.push_back(cnt);
    new_list.push_back(checking);
  }
  int sy = (N+1)/2, sx = (N+1)/2;
  int d1, d2;
  int start = 0;
  bool startChecking = true;
  for (int i = 1; i <= N - 1; i++) {
    if (i % 2 == 0) {
      d1 = 3;
      d2 = 0;
    } else {
      d1 = 2;
      d2 = 1;
    }
    
    for (int s = 0; s < i; s++) {
       sy += dy[d1];
       sx += dx[d1];
       if (new_list.size() <= start) {
          startChecking = false;
          break;
       }
       new_board[sy][sx] = new_list[start++];
    }
    if (!startChecking) break;

    for (int s = 0; s < i; s++) {
       sy += dy[d2];
       sx += dx[d2];
       if (new_list.size() <= start) {
          startChecking = false;
          break;
       }
       new_board[sy][sx] = new_list[start++];
    }
    if (!startChecking) break;

    if (i == N - 1) {
      for (int s = 0; s < i; s++) {
       sy += dy[2];
       sx += dx[2];
       if (new_list.size() <= start) {
          startChecking = false;
          break;
       }
       new_board[sy][sx] = new_list[start++];
      }
    }
    if (!startChecking) break;
  }


  // cout << "\n";
  for (int i = 1; i < N+1; i++) {
    for (int j = 1; j < N+1; j++) {
        board[i][j] = new_board[i][j];
      // cout << new_board[i][j] << " ";
    }
    // cout << "\n";
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  input();

  while (step <= M) {
    // cout << "\n" << "M - " << step << "\n";
    // 1. 상어 d 방향으로 거리가 s 이하인 모든 칸 파괴
    removeBoard();
    // cout << "remove Board\n";
    printBoard();
    // 2. 구슬 이동 & 3. 폭발
    vector<int> lists = bombBoard();
    for (int i = 0; i < lists.size(); i++) {
      // cout << lists[i] << " ";
    }
    // 4. 그룹 별 보드에 추가
    setBoard(lists);
    // cout << "\n";
    ans += ((bomb1*1) + (bomb2*2) + (bomb3*3));
    bomb1 = 0;
    bomb2 = 0;
    bomb3 = 0;
    step ++;
  }
  // 폭발한 구슬 개수 
  cout << ans;
  
}
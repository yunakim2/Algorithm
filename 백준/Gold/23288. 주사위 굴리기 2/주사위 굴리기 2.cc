#include <bits/stdc++.h>

using namespace std;

// 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
// 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
// A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
// A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
// A = B인 경우 이동 방향에 변화는 없다.

// 점수 
// x,y 에 칸 에 있는 정수 b / (x,y) 동서 남북 방향으로 연속해서 이동할 수 있는 칸의 수 C 모두 구한다.
// 이때 , 이동할 수 있는 칸에는 모두 정수 'B'가 있어야 한다. -> B * C 곱한 값이 점수

// 보드의 크기와 각 칸에 있는 정수, 주사위 이동 횟수 K 가 주어졌을 경우 각 이동에서 획득하는 점수의 합을 구해라

int N, M, K;
int board[24][24];
// N - 세로 / M - 가로 / K - 이동횟수

int dy[] = {0, -1, 0, +1};
int dx[] = {+1, 0, -1, 0};

struct model {
  int x, y;
  int d;
  int top;
  int right;
  int front;
};

int ans;

model m;

void input() {
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  m.y = 0;
  m.x = 0;
  m.d = 0;
  m.right = 3;
  m.front = 2;
  m.top = 1;
}

int solution() {
  queue<pair<int, int>> q;
  q.push({m.y, m.x});
  int visited[24][24];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = 0;
    }
  }
  visited[m.y][m.x] = 1;
  int yy, xx, ny, nx;
  while (q.size()) {
    tie(yy,xx) = q.front(); q.pop();
    //cout << "yy - " << yy << " xx - " << xx << "\n";
    for (int k = 0; k < 4; k++) {
      ny = yy + dy[k];
      nx = xx + dx[k];
      if (0 > ny || ny >= N || 0 > nx || nx >= M) continue;
      //cout << visited[ny][nx] << " " << board[ny][nx] << " " << board[m.y][m.x] << "\n";
      if (visited[ny][nx] == 0 && board[ny][nx] == board[yy][xx]) {
        //cout << "ny - " << ny << " nx - " << nx << "\n";
        q.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }

  int max_cnt = 0;
 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == 1) {
        max_cnt += 1;
      }
    }
  }
  //cout << "solution -- " << max_cnt << "\n";
  return max_cnt;
}

void moveXY() {
  int ny, nx;
  ny = m.y + dy[m.d];
  nx = m.x + dx[m.d];
  if (0 > ny || ny >= N || 0 > nx || nx >= M) {
    if (m.d == 1) {
      m.d = 3;
    } else if (m.d == 2) {
      m.d = 0;
    } else if (m.d == 3) {
      m.d = 1;
    } else {
      m.d = 2;
    }
    ny = m.y + dy[m.d];
    nx = m.x + dx[m.d];
  }

  //cout<< "ny - " << ny << " nx - " << nx << "\n";
  m.y = ny;
  m.x = nx;
}

 void moveModel() {
  int top, right, front;
  if (m.d == 0) {
  // 동
     top = 7 - m.right;
     right = m.top;
     front = m.front;
  } else if (m.d == 1) {
  // 북
      top = 7- m.front;
      right = m.right;
      front = m.top;
  } else if (m.d == 2) {
  // 서
    top = m.right;
    front = m.front;
    right = 7 - m.top;
  } else {
  // 남
    top = m.front;
    right = m.right;
    front = 7 - m.top;
  }
  m.top = top;
  m.right = right;
  m.front = front;
}

void setDirection() {
  int A =  7 - m.top;
  int B = board[m.y][m.x];
  //cout << "A - " << A << " B - " << B << "\n";
  if (A == B) {
    return;
  } else if (A > B) {
    m.d = m.d - 1;
    //cout << "**";
    if (m.d < 0) m.d = 3;
    //cout << "kkk - m.d "<< m.d << '\n';
    return;
  } else {
    m.d = m.d + 1;
    if (m.d > 3) m.d = 0;
    return;
  }
  //cout << "setDirection - " << m.d << "\n";
}

int main() {
  input();


  while (K > 0) {
  // 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
    //cout << "\n";
    //cout << "K  - " << K << "\n";
    moveXY();
    moveModel();
    //cout << "** - " << m.y << m.x << "\n";
    //cout << "board [][] " << board[m.y][m.x] << "\n";
    ans += (solution() * board[m.y][m.x]);
    setDirection();
    //cout << "y - " << m.y + 1 << " x - " << m.x + 1 <<  " d - " << m.d  << "\n";
    //cout <<  "top - " << m.top <<  "front - " << m.front << " right - " << m.right << "\n";
    //cout << "ans - " << ans << "\n";
    K--;
  }
  cout << ans;

}
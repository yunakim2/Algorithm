#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
typedef pair<int, int> P;

int N, M;
int A[53][53][2];
vector<P> v;

vector<P> cloud;

int dy[] = {0, -1, -1, -1, 0, 1,1,1};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void input() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j][0];
    }
  }
   P p;
  for (int i = 0; i < M; i++) {
    cin >> p.first >> p.second;
    p.first --;
    v.push_back(p);
  }

  A[N][1][1] = 1;
  A[N][2][1] = 1;
  A[N-1][1][1] = 1;
  A[N-1][2][1] = 1;
  cloud.push_back({N, 1});
  cloud.push_back({N, 2});
  cloud.push_back({N-1, 1});
  cloud.push_back({N-1, 2});
}

void moveCloud(int d, int s) {
  int ny, nx;
  for (int i = 0; i < cloud.size(); i++) {
    ny = cloud[i].first;
    nx = cloud[i].second;
    A[ny][nx][1] = 0;
    for (int j = 1; j <= s; j++) {
      ny += dy[d];
      nx += dx[d];
      if (ny <= 0) ny += N;
      if (nx <= 0) nx += N;
      if (ny > N) ny -= N;
      if (nx > N) nx -= N;
    }
    A[ny][nx][0] += 1;
    cloud[i].first = ny;
    cloud[i].second = nx;
  }
}
void printBoard() {
  cout << "==================\n";
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << A[i][j][0] << " ";
    }
    cout << "\n";
  }
}

void copyCloud() {
  vector<P> new_cloud;
  int y, x;
  int ny, nx;
  int cnt = 0;

  for (int i = 0; i < cloud.size(); i++) {
    y = cloud[i].first;
    x = cloud[i].second;
    cnt = 0;
    for (int k = 1; k < 8; k += 2) {
      ny = y + dy[k];
      nx = x + dx[k];
      if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
      if (A[ny][nx][0] > 0) cnt += 1;
    }
    A[y][x][0] += cnt;
    A[y][x][1] = 1;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i][j][0] >= 2 && A[i][j][1] != 1) {
        new_cloud.push_back({i,j});
        A[i][j][0] -= 2;
      }
    }
  }

  for (int i = 0; i < cloud.size(); i++) {
    y = cloud[i].first;
    x = cloud[i].second;
    A[y][x][1] = 0;
  }

  cloud.clear();
  cloud.shrink_to_fit();


  for (int i = 0; i < new_cloud.size(); i++) {
    y = new_cloud[i].first;
    x = new_cloud[i].second;
    A[y][x][1] = 1;
    cloud.push_back({y, x});
  }
}

void solution() {
  int d, s;
  for (int i = 0; i < M; i++) {
    d = v[i].first;
    s = v[i].second;
    // 1. 모든 구름 d 방향으로 s 칸 이동
    moveCloud(d, s);
    // 2. 구름 칸 물 1 증가
    // addBoard();
    // 3. 물이 증가한 칸 복사 시작
    copyCloud();
  }
}


void output() {
  int sums = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i][j][0] > 0) {
        sums += A[i][j][0];
      }
    }
  }
  cout << sums;
}

int main() {

  // 비바라기 시전
  // (N,1) (N,2) (N-1, 1) (N-1,2) 비구름 생김
  // M 번 명령 
  input();

  solution();

  output();

  // 2.  물의 양 1 증가
  // 3. 구름 사라짐
  // 4. 2에서 증가한 칸에 물복사 버그 마법 시전 
  // 마법 사용 -> 대각선 방향 거리 1인 칸에 물이 있는 바구니 수만 큼 (r,c) 바구니 물 증가
  // ** 이때는 1, n행 열 안 이어져 있음

}
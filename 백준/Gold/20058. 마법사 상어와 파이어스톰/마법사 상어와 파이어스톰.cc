#include <iostream>
#include <vector>
#include <cstring>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// 회전 가능 레벨
int N;
// 회전 횟수
int Q;

int SIZE;
queue<int> rotateLevel;
int arr[68][68];
int rotates[68][68];
int visited[68][68];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int allSize = 0;

int totalSize = 0;


void printArr() {
    // cout << "\n";
    // cout << "================\n";
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }
    // cout << "================\n";
    // cout << "\n";
}

void initRotate() {
     for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            rotates[i][j]  =  -1;
        }
    }
}


void printRotate() {
    // cout << "\n";
    // cout << "================\n";
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // cout << rotates[i][j] << " ";
        }
        // cout << "\n";
    }
    // cout << "================\n";
    // cout << "\n";
}

int getBfs(int y, int x) {
    queue< pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = 1;
    int cnt = 1;
    allSize += arr[y][x];
    while(q.size()) {
        pair<int, int> xy = q.front(); q.pop();
        int yy = xy.first;
        int xx = xy.second;

        for(int i = 0; i < 4; i++) {
            int ny = yy+dy[i];
            int nx = xx +dx[i];

            if (0 > ny || ny >= SIZE || 0 > nx || nx >= SIZE) continue;
            if (visited[ny][nx] == 0 && arr[ny][nx] > 0) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
                allSize += arr[ny][nx];
                cnt += 1;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> Q;
    SIZE = pow(2, N);

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> arr[i][j];
            totalSize += arr[i][j];
        }
    }


    // cout << "total ----" << totalSize << "\n";
    for(int i = 0 ; i < Q; i++) {
        int t;
        cin >> t;
        rotateLevel.push(t);
    }

    
    // 회전을 모두 끝낸 뒤 남아있는 빙하의 총 양 출력
    while(rotateLevel.size()) {
        int level = rotateLevel.front();
        rotateLevel.pop();

        vector< pair<int, int> > v;
        int K = pow(2, level);
        int R = pow(2, level-1);

        for(int pp = 0; pp <= level; pp++) {    
            if (pp == 0) continue;
            initRotate();
            int K = pow(2, pp);
            int R = pow(2, pp-1);
            for(int ty = 0; ty < SIZE; ty = ty + K) {
                for(int tx = 0; tx < SIZE; tx = tx + K) {
                    int cy = ty;
                    int cx = tx;
                    for(int k = 0; k < 4; k++) {
                        for(int y = cy; y < cy + R; y++) {
                            for(int x = cx; x < cx + R; x++) {
                                rotates[y][x] = k;
                            }
                        }
                        if (k == 0) {
                            cy = cy;
                            cx = cx + R;
                        } else if (k == 1) {
                            cy = cy + R;
                            cx = cx;
                        } else if (k == 2) {
                            cy = cy;
                            cx = cx - R;
                        }
                    }
                }
            }

            // cout << "level : " << level << "\n";
            // cout << "좌표에 회전 방향 설정\n";
            printRotate();

            int new_arr[68][68] = {0, };
            for(int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                    if(rotates[i][j] == -1) {
                        new_arr[i][j] = arr[i][j];
                    } else {
                        int ny = i + (dy[rotates[i][j]] * R);
                        int nx = j + (dx[rotates[i][j]] * R);
                        new_arr[ny][nx] = arr[i][j];
                    }
                }
            }

            memcpy(arr, new_arr, sizeof(new_arr));
            // cout << "회전 성공 \n";
            // cout << "\n";
            printArr();
        }
 

        // 회전 끝나고 빙하에 속한 얼음이 녹는다. 
        // 한칸 기준, 상하좌우 인접칸에 얼음이 3개 이상인 경우 녹지 X;
        int new_arr[68][68] = {0, };
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                int yy = i;
                int xx = j;
                int cnt = 0;
                for(int d = 0; d < 4; d++) {
                    int sy = yy + dy[d];
                    int sx = xx + dx[d];
                    if (0 > sy || sy >= SIZE || 0 > sx || sx >= SIZE) continue;
                    if (arr[sy][sx] <= 0) continue;
                    cnt ++;
                }
                if (cnt < 3) {
                    new_arr[i][j] = arr[i][j] -1;
                    if (new_arr[i][j] < 0) new_arr[i][j] = 0;
                } else {
                    new_arr[i][j] = arr[i][j];
                }
            }
        }
        memcpy(arr, new_arr, sizeof(new_arr));

        // cout << "빙하 녹이기\n";
        printArr();
    }

    int maxCnt = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if (visited[i][j] == 0 && arr[i][j] > 0) {
                maxCnt = max(maxCnt, getBfs(i, j));
            }
        }
    }

    cout << allSize << "\n";
    cout << maxCnt;
}
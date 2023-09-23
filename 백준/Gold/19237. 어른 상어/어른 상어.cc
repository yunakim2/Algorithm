// 상어 1 ~ M 자연수


// 1. 인접한 칸 중 아무 냄새가 없는 칸 방향,
// 2. 자신의 냄새가 있는 칸으로 방향 (특정한 우선순위를 따른다)

#include <bits/stdc++.h>

using namespace std;

struct shark {
    int num;
    int y, x, d;
    bool alive = true;
};

struct maps {
    int num, cnt;
    int shark = -1;
};

int times = 0;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int N, M, K;
maps board[24][24];
vector<shark> sh;
int direction[404][4][4];

void input() {
    cin >> N >> M >> K;
    int tmp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp != 0) {
                shark s;
                s.num = tmp-1;
                s.alive = true;
                s.x = j;
                s.y = i;
                sh.push_back(s);
            }
            board[i][j].cnt = 0;
            board[i][j].num = tmp-1;
            board[i][j].shark = -1;
        }
    }
    sort(sh.begin(), sh.end(), [](shark prev, shark next){
        return prev.num < next.num;
    });
    for(int i = 0; i < M; i++) {
        cin >> sh[i].d;
        sh[i].d -=1;
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                cin >> direction[i][j][k];
                direction[i][j][k] -=1;
            }
        }
    }

}

void spreadShark() {
    for(int i = 0; i < M; i++) {
        if (sh[i].alive == false) continue;
        board[sh[i].y][sh[i].x].shark = sh[i].num;
        board[sh[i].y][sh[i].x].cnt = K;
    }
}

void moveShark() {
    int x, y, d;
    int new_d;
    int nx, ny;
    for(int i = 0; i < M; i++) {
        if (sh[i].alive == false) continue;
        x = sh[i].x;
        y = sh[i].y;
        d = sh[i].d;
        bool checking = false;
        for(int k = 0; k < 4; k++) {
            new_d = direction[i][d][k];
            nx = x + dx[new_d];
            ny = y + dy[new_d];
            if (0> nx || nx >= N || 0 > ny || ny >= N) continue;
            // 1. 아무 냄새도 없는 곳
            if (board[ny][nx].cnt == 0) {
                if (board[ny][nx].num != -1) {
                    board[y][x].num = -1;
                    sh[i].alive = false;
                    checking = true;
                } else {
                    board[y][x].num = -1;
                    board[ny][nx].num = i;
                    sh[i].y = ny;
                    sh[i].x = nx;
                    sh[i].d = new_d;
                }
                checking  = true;
                break;
            }
        }
        if (checking) continue;
        for(int k = 0; k < 4; k++) {
            // 2. 자신의 냄새가 있는 곳
            new_d = direction[i][d][k];
            nx = x + dx[new_d];
            ny = y + dy[new_d];
            if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
            if (board[ny][nx].shark == i) {
                board[y][x].num = -1;
                board[ny][nx].num = i;
                sh[i].y = ny;
                sh[i].x = nx;
                sh[i].d = new_d;
                break;
            }
        }
    }
}

void setShark() {
    for(int i = 0; i < M; i++) {
        // cout << "start ! - " << i << " \n";
        // cout << "(" << sh[i].y <<","<< sh[i].x << ")\n";
        if (sh[i].alive == false) continue;
        for(int j = i+1; j < M; j++) {
            if (sh[j].alive == false) continue;
            if (sh[j].y == sh[i].y && sh[j].x == sh[i].x) {
                sh[j].alive = false;
                // cout << "j - " << j << "false!\n";
            }
        }
    }
}

int checkingShark() {
    int cont = 0;
    for(int i = 0; i < M; i++) {
        if (sh[i].alive == true) cont += 1;
    }
    return cont;
}

void removeSmell() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (board[i][j].cnt > 0) {
                board[i][j].cnt -=1;
            }
            if (board[i][j].cnt == 0) {
                board[i][j].shark = -1;
            }
        }
    }
}

void printBoard() {
    cout << "\n";
    cout << "====================\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j].num+1 << " ";
        }
    cout << "\n";
    }
    cout << "====================\n"; 
    cout << "\n";

    cout << "\n";
    cout << "*********************\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j].shark+1 << " ";
        }
    cout << "\n";
    }
    cout << "*********************\n"; 
    cout << "\n";

    cout << "\n";
    cout << "######################\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j].cnt << " ";
        }
    cout << "\n";
    }
    cout << "######################\n"; 
    cout << "\n";
}

void setBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j].num = -1;
        }
    }
    for(int i = 0; i < M; i++) {
        if (sh[i].alive == false) continue;
        board[sh[i].y][sh[i].x].num = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    while(true) {
        times += 1;
        if (times > 1000) break;
        spreadShark();
        // cout << "times " << times << "시작 \n";
        // printBoard();
        // 1. 상어 자신의 위치에 냄새 뿌림
        // 냄새 k 번 이동 후, 제거  
        moveShark();
        // 2. 모든 상어 동시에 상하좌우 인접한 칸 중 하나 이동
        // setShark();
        // setBoard();
        // 3. 자신의 냄새를 그 칸에 뿌린다.
        removeSmell();
        spreadShark();
        // cout << "times " << times << "끝 \n";
        // printBoard();
        if (checkingShark() == 1) {
            break;
        }
    } 

    if (times > 1000) {
        cout << -1;
    } else {
        cout << times;
    }

}
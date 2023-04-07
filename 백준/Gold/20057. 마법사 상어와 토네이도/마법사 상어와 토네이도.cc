#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505][505];
struct xy {
    int y, x, d;
};

xy robot;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// int moving[505][505];
int outDust = 0;
int cnt = 0;
int num = 0;

void printArr() {
    // // cout << "---------------\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // // cout << arr[i][j] << " ";
        }
        // // cout << "\n";
    }
}

void printMovingArr() {
    // // cout << "---------------\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // // cout << moving[i][j] << " ";
        }
        // // cout << "\n";
    }
}

// void setMovingArr() {
//     int num = 1;
//     int x = 0;
//     int y = 0;
//     for(int i = 0; i < N; i++) {
//         moving[y][x++] = num ++;
//     }
//     x = N-1;
//     int sign = 1;
//     for(int i = N-1; i > 0; i--) {
//         for(int j = 0; j < i; j++) {
//             y+= sign;
//             moving[y][x] = num++;
            
//         }
//         sign *= -1;

//         for(int j = 0; j < i; j++) {
//             x+= sign;
//             moving[y][x] = num++;
//         }
//     }

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             moving[i][j] = N*N -moving[i][j];
//         }
//     }
// }

bool checkingBound(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < N) return true;
    return false;
}

// void getRobotXY() {
//     int x = robot.x;
//     int y = robot.y;
//     int d = robot.d;
//     for(int i = 0; i < N; i++) {
//         bool checking = false;
//         for(int j = 0; j < N; j++) {
//             if (moving[i][j] == cnt + 1) {
//                 y = i;
//                 x = j;
//                 checking = true;
//                 break;
//             }
//         }
//         if (checking) break;
//     }


//     for(int i = 0; i < 4; i++) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if ( 0 > nx || nx >= N || 0 > ny || ny >= N) continue;
//         if (moving[ny][nx] == cnt) {
//             d = (i + 2) % 4;
//         }
//     }

//     robot.d = d;
//     robot.y = y;
//     robot.x = x;

    // // cout << "num : " << cnt << "==========\n";
    // // cout << "robot y  : " << y << " x : " << x << " d : " << d << "\n";
// }

void setDust() {

    // cout << robot.y << " : " << robot.x << " : " << robot.d << "\n";

    int dustSize = arr[robot.y][robot.x];
    int x = robot.x;
    int y = robot.y;
    int d = robot.d;
    int dust7 = int(dustSize * 0.07);
    int dust1 = int(dustSize * 0.01);
    int dust10 = int(dustSize * 0.1);
    int dust5 = int(dustSize * 0.05);
    int dust2 = int(dustSize *0.02);
    int dust = dustSize - (dust10 + dust1 + dust7 + dust2) * 2 - dust5;

    // // cout << "dustSize : " << dustSize;
    // // cout << "dust1 : " << dust1 << " dust7 : " << dust7 << " dust10 : " << dust10 << "\n";
    // // cout << "dust5 : " << dust5 << "dust : " << dust << "\n";
    if (robot.d == 2 || robot.d == 0) {
        if (checkingBound(y-1, x)) {
            arr[y-1][x] += dust7;
        } else {
            outDust += dust7;
        }

        if (checkingBound(y+1, x)) {
            arr[y+1][x] += dust7;
        } else {
            outDust += dust7;
        }

        if (checkingBound(y-1, x-dx[d])) {
            arr[y-1][x-dx[d]] += dust1;
        } else {
            outDust += dust1;
        }

        if (checkingBound(y+1, x-dx[d])) {
            arr[y+1][x-dx[d]] += dust1;
        } else {
            outDust += dust1;
        }
        if (checkingBound(y+1, x+dx[d])) {
            arr[y+1][x+dx[d]] += dust10;
        } else {
            outDust += dust10;
        }

        if (checkingBound(y-1, x+dx[d])) {
            arr[y-1][x+dx[d]] += dust10;
        } else {
            outDust += dust10;
        }
        if (checkingBound(y-2, x)) {
            arr[y-2][x] += dust2;
        } else {
            outDust += dust2;
        }
        if (checkingBound(y+2, x)) {
            arr[y+2][x] += dust2;
        } else {
            outDust += dust2;
        }

    } else {
        if (checkingBound(y, x-1)) {
            arr[y][x-1] += dust7;
        } else {
            outDust += dust7;
        }
        if (checkingBound(y, x+1)) {
            arr[y][x+1] += dust7;
        } else {
            outDust += dust7;
        }

        if(checkingBound(y, x-2)) {
            arr[y][x-2] += dust2;
        } else {
            outDust += dust2;
        }
        if (checkingBound(y, x+2)) {
            arr[y][x+2] += dust2;
        } else {
            outDust += dust2;
        }

        if (checkingBound(y-dy[d], x-1)) {
            arr[y-dy[d]][x-1] += dust1;
        } else {
            outDust += dust1;
        }

        if (checkingBound(y-dy[d], x+1)) {
            arr[y-dy[d]][x+1] += dust1;
        } else {
            outDust += dust1;
        }


        if (checkingBound(y+dy[d], x-1)) {
            arr[y+dy[d]][x-1] += dust10;
        } else {
            outDust += dust10;
        }


        if (checkingBound(y+dy[d], x+1)) {
            arr[y+dy[d]][x+1] += dust10;
        } else {
            outDust += dust10;
        }
    }

    int ny = y + dy[robot.d] + dy[robot.d];
    int nx = x + dx[robot.d] + dx[robot.d];
    if (checkingBound(ny, nx)) {
        arr[ny][nx] += dust5;
    } else {
        outDust += dust5;
    }
    ny = y + dy[robot.d];
    nx = x + dx[robot.d];
    if (checkingBound(ny, nx)) {
        arr[ny][nx] += dust;
    } else {
        outDust += dust;
    }

    // cout << num << " - 먼지 : " << outDust << "\n";
    arr[robot.y][robot.x] = 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 왼, 아, 오, 위 순으로 청소
    // 항상 왼쪽 위에서 끝나게 됨
    // 빗자루가 이동 할 때마다 빗자루가 이동한 위치의 있는 먼지가 함께 이동하는데
    // 아래 비율을 맞춰 이동하게 됨
    // 이동한 먼지는 기존 먼지양에 더해지고, 
    // 빗자루가 이동한 위치의 먼지는 모두 없어짐
    // a%에 해당하는 먼지의 양
    // 다른 격자에 이동한 먼지의 양을 모두 합한 것을 이동한 위치에 있던 먼지의 양에서 빼고 남은 먼지에 해당함
    // 비율을 곱할때 소수점 아래 숫자 모두 버림

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    robot.x = N/2;
    robot.y = N/2;
    robot.d = 0;
    for(int i = 1; i < N; i++) {
        for(int k = 0; k < 2; k++) {
            for(int j = 0; j < i; j++) {
                num++;
                robot.x += dx[robot.d];
                robot.y += dy[robot.d];
                setDust();
             }
            robot.d = (robot.d + 1) % 4;
        }
    }

    for(int i = 0; i < N-1; i++) {
        robot.x += dx[robot.d];
        robot.y += dy[robot.d];
        setDust();
    }

    cout << outDust;

}
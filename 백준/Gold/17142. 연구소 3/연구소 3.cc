#include <bits/stdc++.h>

using namespace std;
int arr[55][55];
vector< pair<int, int> > v;
int visited[55][55];
int counts[55][55];
int N, M;
int checking[13];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int ans = 10004;
struct moving {
    int x, y, cnt;
};


void cal(queue< moving > active) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = 0;
            counts[i][j] = -1;
            if (arr[i][j] == 1) {
                visited[i][j] = 1;
            }
        }
    }

    while(active.size()) {
        moving xy = active.front(); active.pop();
        int x = xy.x;
        int y = xy.y;
        int move = xy.cnt;
        visited[y][x] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            if (visited[ny][nx] == 0 && arr[ny][nx] != 1) {
                moving m;
                m.x = nx;
                m.y = ny;
                counts[ny][nx] = move + 1;
                m.cnt = move + 1;
                visited[ny][nx] = 1;
                active.push(m);
            }
        }
    }
    int max_cnt = 0;
    bool ans_check = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (arr[i][j] == 0) {
                if (visited[i][j] == 0) {
                    ans_check = false;
                    break;
                } else {
                    max_cnt = max(max_cnt, counts[i][j]);
                }
            }
        }
    }
    if (ans_check) {
        ans = min(ans, max_cnt);
    }
}

void dfs(int start, int check[], int cnt) {
    if (cnt == M) {
        queue< moving > virus;
        for(int i = 0; i < v.size(); i++) {
            if (check[i]) {
                moving m;
                m.x = v[i].second;
                m.y = v[i].first;
                m.cnt = 0;
                virus.push(m);
            }
        }
        cal(virus);
        return;
    }
    for(int i = start; i < v.size(); i++) {
        if (check[i] == 1) continue;
        check[i] = 1;
        dfs(i, check, cnt + 1);
        check[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    int temp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            arr[i][j] = temp;
            if (temp == 2) {
                v.push_back({i, j});
            }
        }
    }

    dfs(0, checking, 0);
    if (ans == 10004) {
        cout << -1;
    } else {
        cout << ans;
    }
}
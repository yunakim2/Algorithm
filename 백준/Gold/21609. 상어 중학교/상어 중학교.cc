#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[25][25];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int blockGroup[25][25];
int visited[25][25];

struct Block {
    int y, x, cnt, rainbow;
};
int ans = 0;

pair<int, int> findBlockMap(int y, int x) {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            blockGroup[i][j] = 0;
        }
    }

    int color = arr[y][x];
    queue < pair<int, int> > q;
    q.push({y, x});
    blockGroup[y][x] = color;

    while(q.size()) {
        pair<int, int> xy = q.front(); q.pop();
        int xx = xy.second;
        int yy = xy.first;
        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            if (arr[ny][nx] == -1) continue;
            if (blockGroup[ny][nx] == 0 && (arr[ny][nx] == 0 || arr[ny][nx] == color) ) {
                if (arr[ny][nx] == color) visited[ny][nx] = 1;
                blockGroup[ny][nx] = color;
                q.push({ny, nx});
            }
        }
    }

    int cnt = 0;
    int rainbow = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (blockGroup[i][j] == color) {
                if (arr[i][j] == 0) rainbow += 1;
                cnt += 1;
            }
        }
    }
    return {rainbow, cnt};
}

void removeBlock() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (blockGroup[i][j] != 0) {
                arr[i][j] = -2;
            }
        }
    }
}

void moveBlock() {
    int new_map[25][25];
    fill(new_map[0], new_map[25], -2);
    for (int j = 0; j < N; j++) {
      for (int i = N-1; i >= 0; i--) {
        if (arr[i][j] == -1) {
          new_map[i][j] = -1;
          continue;
        }
        if (arr[i][j] == -2) {
          continue;
        }
        if (i == N - 1) {
          new_map[i][j] = arr[i][j];
          continue;
         }
        int k;
        for (k = i + 1; k < N; k++) {
          if (new_map[k][j] != -2) break;
        }
        new_map[k-1][j] = arr[i][j];
      }
    }
    memcpy(arr, new_map, sizeof(new_map));
    return;
}



void rotateBlock() {
    int new_map[25][25];
    fill(new_map[0], new_map[25], 0);

    for (int i = 0; i < N; i++) {
      for (int j = N-1; j >= 0; j--) {
        new_map[N-1-j][i] = arr[i][j];
      }
    }
    memcpy(arr, new_map, sizeof(new_map));
    return;
}

int main() {
    cin >> N >> M;
    int temp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    while(true) {
      vector < Block > blocks;
      fill(visited[0], visited[25], 0);
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (visited[i][j] == 0 && arr[i][j] >= 1) {
                pair<int, int> cal = findBlockMap(i, j);
                if (cal.second >= 2) {
                    Block b;
                    b.x = j;
                    b.y = i;
                    b.rainbow = cal.first;
                    b.cnt = cal.second;
                    blocks.push_back(b);
                }
            }
        }
        }
        if (blocks.size() == 0) break;
        Block max_block;
        max_block.cnt = 0;
        max_block.x = 0;
        max_block.y = 0;
        max_block.rainbow = 0;
        for(int i = 0; i < blocks.size(); i++) {
            Block che_block = blocks[i];
            if (max_block.cnt <= che_block.cnt) {
                if (max_block.cnt == che_block.cnt) {
                    if (max_block.rainbow <= che_block.rainbow) {
                        if (max_block.rainbow == che_block.rainbow) {
                            if (max_block.y <= che_block.y) {
                                if (max_block.y == che_block.y) {
                                    if (max_block.x < che_block.x) {
                                        max_block = che_block;
                                    }
                                } else {
                                    max_block = che_block;
                                }
                            }
                        } else {
                            max_block = che_block;
                        }
                    }
                } else {
                    max_block = che_block;
                }
            }
        }
        pair<int, int> temps = findBlockMap(max_block.y, max_block.x);
        ans += ((temps.second) * (temps.second));
        removeBlock();
        moveBlock();
        rotateBlock();
        moveBlock();
     }
    cout << ans;
}
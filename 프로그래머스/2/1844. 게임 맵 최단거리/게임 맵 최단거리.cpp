#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};

int visited[104][104] = {0, };
int mapSize;
int n,m;

void bfs(int y, int x, vector<vector<int> > maps) {
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    
    while(q.size()) {
        pair<int,int> yx = q.front();
        q.pop();
        int yy = yx.first;
        int xx = yx.second;
        for(int k = 0; k < 4; k++) {
            int ny = yy + dy[k];
            int nx = xx + dx[k];
            if (0 > ny || ny >= n || 0 > nx || nx >= m) {
                continue;
            }
            if (visited[ny][nx] == 0 && maps[ny][nx] == 1) {
                visited[ny][nx] = visited[yy][xx] + 1;
                q.push({ny,nx});
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    bfs(0, 0, maps);
    if (visited[n-1][m-1] == 0) { return -1;}
    return visited[n-1][m-1];
}
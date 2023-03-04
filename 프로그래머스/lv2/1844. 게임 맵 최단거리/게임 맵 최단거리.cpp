#include<bits/stdc++.h>

using namespace std;
int visited[104][104] = {0, };
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int solution(vector<vector<int> > maps)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(q.size()) {
        auto xy = q.front(); q.pop();
        int x = xy.first;
        int y = xy.second;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= maps.size() || 0 > ny || ny >= maps[0].size()) {
                continue;
            }
            if (!visited[nx][ny] && maps[nx][ny] == 1) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return (visited[maps.size()-1][maps[0].size()-1] != 0) ? visited[maps.size()-1][maps[0].size()-1] : -1;
}
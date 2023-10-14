#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int visited[104];
int used[100004];

int bfs(vector<vector<int>> wires, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;
    while(q.size()) {
        int qq = q.front();
        q.pop();
        cnt++;
        for(int i = 0; i < wires.size(); i++) {
            if (used[i]) continue;
            if(wires[i][0] == qq  && !visited[wires[i][1]]) {
                visited[wires[i][1]] = true;
                q.push(wires[i][1]);
            }
            if (wires[i][1] == qq && !visited[wires[i][0]]) {
                visited[wires[i][0]] = true;
                q.push(wires[i][0]);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i = 0; i < wires.size(); i++) {
        used[i] = true;
        fill(visited, visited+104, false);
        int cnts = bfs(wires, 1);
        used[i] = false;
        
        answer = min(answer, abs(cnts - (n-cnts)));
    }
    
    return answer;
}
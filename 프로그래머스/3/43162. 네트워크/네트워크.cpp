#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[204];

void dfs(vector<vector<int>> &computers, int n,  int start) {
    for(int k = 0; k < n; k++) {
        if (k == start) continue;
        if (!visited[k] && computers[start][k] == 1) {
            visited[k] = 1;
            dfs(computers, n, k);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(computers, n, i);
            answer ++;
        }
    }
    return answer;
}
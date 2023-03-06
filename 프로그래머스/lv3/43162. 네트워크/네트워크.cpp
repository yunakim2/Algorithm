#include <bits/stdc++.h>

using namespace std;

int visited[204];
int K;
vector<int> arr[204];

void dfs(int start) {
    for(int there : arr[start]) {
        if(!visited[there]) {
            visited[there] = 1;
            dfs(there);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    K = computers.size();
    for(int i = 0; i < computers.size(); i++) {
        for(int j = 0; j < computers.size(); j++) {
            if (i == j) continue;
            if (computers[i][j]) {
                arr[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < computers.size(); i++) {
        if (!visited[i]) {
            dfs(i);
            answer += 1;
        }
    }
    return answer;
}
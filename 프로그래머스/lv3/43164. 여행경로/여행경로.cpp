#include <bits/stdc++.h>

using namespace std;
int visited[10004];
vector<string> ans;
bool flag = false;
int cnt = 0;

void dfs(string start, vector<vector<string>> tickets) {
    if (cnt == tickets.size()) {
        flag = true;
    }
    ans.push_back(start);
    for(int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && !visited[i]) {
            visited[i] = 1;
            cnt++;
            dfs(tickets[i][1], tickets);
            if (!flag) {
                ans.pop_back();
                visited[i] = 0;
            }
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return ans;
}
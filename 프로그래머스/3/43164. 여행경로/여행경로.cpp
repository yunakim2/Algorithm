#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<vector<string>> answer;
int visited[10004];


void dfs(string start,vector<string> res, vector<vector<string>> tickets, int count) {
    if (count == tickets.size()) {
        answer.push_back(res);
        return;
    }
    
    for(int k = 0; k < tickets.size(); k++) {
        if(tickets[k][0] == start && !visited[k]) {
            visited[k] = 1;
            res.push_back(tickets[k][1]);
            dfs(tickets[k][1],res, tickets, count +1 );
            res.pop_back();
            visited[k] = 0;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> ans;
    ans.push_back("ICN");
  
    
    sort(tickets.begin(), tickets.end(), [](vector<string> t1, vector<string> t2)         {
        if (t1[0] == t2[0]) return t1[1] < t2[1];
        return t1[0] < t2[0];
    });
    
    dfs("ICN", ans, tickets, 0);

    return answer[0];
}
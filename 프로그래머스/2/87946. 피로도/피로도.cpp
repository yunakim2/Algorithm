#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visited[10];
int ans = -1;


void dfs(int empty_k, int count, vector<vector<int>> &dungeons) {
        
    ans = max(ans, count);
    
    for(int start = 0; start < dungeons.size(); start++) {
        if (empty_k >= dungeons[start][0] && visited[start] == false) {
            visited[start] = true;
            dfs(empty_k - dungeons[start][1], count+1, dungeons);
            visited[start] = false;
            
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k,0, dungeons);
    return ans;
}
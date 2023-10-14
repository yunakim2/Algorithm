#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> words {"A", "E", "I", "O", "U"};
set<string> s;

void dfs(int start, int cnt, string str, int exit) {
    if (exit == cnt) {
        // cout << str << "\n";
        s.insert(str);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        dfs(i, cnt+1, str+words[i], exit);
    }
}

int solution(string word) {
    int answer = 1;
    
    for(int i = 1; i <= words.size(); i++) {
        dfs(0, 0, "", i);
    }
    
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        if (word == *iter) {
            return answer;
        }
        answer++;
    }
   
    return answer;
}
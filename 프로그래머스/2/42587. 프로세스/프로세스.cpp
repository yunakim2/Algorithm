#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> process;
    vector<bool> alive;
    for(int i = 0; i < priorities.size(); i++) {
        process.push({i, priorities[i]});
        alive.push_back(true);
    }
    int start = 1;
    while(process.size()) {
        auto pro = process.front();
        process.pop();
        int prior = pro.second;
        bool checking = true;
        for(int i = 0; i < priorities.size(); i++) {
            if (alive[i]) {
                if (priorities[i] > prior) {
                    checking = false;
                    break;                                        
                }
            }
        }
        if (!checking) {
            process.push(pro);
        } else {
            alive[pro.first] = false;
            if (pro.first == location) return start;
            start ++;
        }        
    }
    return answer;
}
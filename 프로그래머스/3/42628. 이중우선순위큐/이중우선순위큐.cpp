#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    
    string command;
    int item;
    int cnt = 0;
    for(const auto &oper : operations) {
        item = stoi(oper.substr(2));
        command = oper.substr(0,1);
        
        if(command == "I") {
            max_q.push(item);
            min_q.push(item);
            cnt ++;
        } else if (command == "D" && cnt > 0){
            if (item == 1) {
                if (cnt != 0) max_q.pop();
            } else {
                if (cnt != 0) min_q.pop();
            }
            cnt --;
            if (cnt == 0) {
                while(max_q.size()) {
                    max_q.pop();
                }
                while (min_q.size()) {
                    min_q.pop();
                }
            }
        }
       
    }
    vector<int> answer;
    
    if (cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(max_q.top());
        answer.push_back(min_q.top());
    }
    return answer;
}
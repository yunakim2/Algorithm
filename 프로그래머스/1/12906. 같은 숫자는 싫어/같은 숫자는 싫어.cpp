#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue <int> q;
    
    for(auto ch : arr) {
        q.push(ch);
    }
    
    while(q.size()) {
        int ch = q.front();
        q.pop();
        while(q.size() && q.front() == ch) {
            q.pop();
        }
        answer.push_back(ch);
        
    }

    return answer;
}
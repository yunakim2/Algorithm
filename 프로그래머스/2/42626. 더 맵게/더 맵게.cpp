#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(const int sc : scoville) {
        pq.push(sc);
    }
    
    int sco, sco1;
    while (true) {
        sco = pq.top();        
        if (sco >= K) break;
        if (pq.size() == 1) return -1;
        pq.pop();
        sco1 = pq.top();
        pq.pop();
        pq.push(sco + (sco1*2));
        answer += 1;
    }
    return answer;
}
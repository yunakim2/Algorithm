#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int prefix[104];
    
    int pro, spe;
    for(int i = 0; i < progresses.size(); i++) {
        pro = progresses[i];
        spe = speeds[i];
        
        int cal = ceil((100.0-pro)/spe);
        if (i == 0) {
            prefix[i] = cal;
        } else {
            prefix[i] = max(prefix[i-1], cal);
        }
    }
    
    int idx = 0;
    int cnt = 0;
    int num = 0;
    int j = 0;
    for(idx = 0; idx < progresses.size();) {
        num = prefix[idx];
        cnt = 1;
        for(j = idx + 1; j < progresses.size(); j++) {
            if (prefix[j] != num) {
                break;
            }
            cnt ++;
        }
        idx = j;
        
        answer.push_back(cnt);
    }
    return answer;
}
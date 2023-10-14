#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[10004];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int cnt = 0;
    
    for(int i = 0; i < prices.size(); i++) {
        cnt = 0;
        for(int k = i+1; k < prices.size(); k++) {
            cnt ++;
            
            if (prices[i] > prices[k]) {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
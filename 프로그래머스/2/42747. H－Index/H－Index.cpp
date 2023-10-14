#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    vector<pair<int, int>> v;
    
    int idx = 0;
    if (citations.size() == 1) {
        return citations[0];
    }
    for(int i : citations) {
        if (idx >= i) {
            return idx;
        }
        idx++;
    }
    return idx;
}
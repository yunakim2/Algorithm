#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(const auto &clothe : clothes) {
        m[clothe[1]] += 1;
    }
    for(const auto &maps : m) {
        answer *= (maps.second +1);
    }
    return answer-1;
}
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map <char, int> m;
    for (int i = 0; i < s.length(); i++) {
        if (m.find(s[i]) == m.end()) {
            answer.emplace_back(-1);
            m.insert({s[i], i});
        } else {
            answer.emplace_back(i-m[s[i]]);
            m.erase(s[i]);
            m.insert({s[i], i});
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string getBinaryStr(string s) {
    int s_size = s.length();
    string new_str = "";
    vector<int> v;
    while(s_size > 1) {
        v.push_back(s_size % 2);
        s_size = s_size / 2;
    }
    v.push_back(1);
    for (int i = v.size() -1; i >= 0; i--) {
        new_str += to_string(v[i]);
    }
    return new_str;
}
vector<int> solution(string s) {
    vector<int> answer;
    if (s == "1") return {0, 0};
    int num = 0;
    int cnt = 0;
    while(num < 6) {
        string temp;
        for (auto &ss : s) {
            if (ss == '0') {
                cnt += 1;
                continue;
            }
            temp += ss;
        }
        s = getBinaryStr(temp);
        num += 1;
        if (s == "1") break;
        
    }
    return {num, cnt};
}
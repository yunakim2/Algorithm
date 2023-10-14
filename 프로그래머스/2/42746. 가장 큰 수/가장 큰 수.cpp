#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> s;
    string answer = "";
    for(int i : numbers) {
        s.push_back(to_string(i));
    }
    
    sort(s.begin(), s.end(), [](string s1, string s2) {
        if (s1+s2 > s2+s1) return true;
        return false;
    });
    
    for(int k = 0; k < s.size(); k++) {
        answer += s[k];
    }
    
     if (answer[0] == '0')
        answer = "0";


    return answer;
}
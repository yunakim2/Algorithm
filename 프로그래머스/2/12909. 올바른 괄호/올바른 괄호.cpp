#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stacks;
    int right = 0;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stacks.push(s[i]);
            ++right;
        } else {
            if (stacks.size() == 0) return false;
            stacks.pop();
            right --;
        }
    }
    if (right > 0) return false;
    return answer;
}
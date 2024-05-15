#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 1;
    if (A == B) return 0;
    int k = A.size();
    string temp = A;
    string new_temp = "";
    int a = 1;
    while(true) {
        new_temp = "";
        new_temp += temp[k-1];
        for(int i = 0; i < A.size()-1; i++) {
            new_temp += temp[i];
        }
        if (new_temp == B) return answer;
        if (answer > k) break;
        answer ++;
        temp = new_temp;
    }
    return -1;
}
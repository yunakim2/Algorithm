#include <bits/stdc++.h>

using namespace std;

int getBinaryOne(int num) {
    int n = num;
    int ans = 0;
    while(n > 1) {
        if (n % 2 == 1) ans += 1; 
        n = n / 2;
    }
    return ans + 1;
}
int solution(int n) {
    int answer = n+1;
    int nums = getBinaryOne(n);
    while(true) {
        if (nums == getBinaryOne(answer)) {
            break;
        }
        answer += 1; 
    } 
    return answer;
}
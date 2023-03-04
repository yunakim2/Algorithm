#include <bits/stdc++.h>

using namespace std;

int answer;
int N;
vector<int> v;

void dfs(int start, int sums) {
    if (start == v.size()) {
        if(sums == N) {
            answer += 1;
        }
        return;
    }
    dfs(start + 1, sums - v[start]);
    dfs(start + 1, sums + v[start]);
    return;
}


int solution(vector<int> numbers, int target) {
    for(int i = 0; i < numbers.size(); i++) {
        v.push_back(numbers[i]);
    }
    N = target;
    dfs(0, 0);
    return answer;
}
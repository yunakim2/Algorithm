#include <string>
#include <vector>

using namespace std;
int answer = 0;
int N;
int targetNum;
vector<int> numberss;

void dfs(int start, int total_sum) {
    if (start >= N) {
        if (total_sum == targetNum) answer += 1;
        return;
    }
    dfs(start + 1, total_sum + numberss[start]);
    dfs(start + 1, total_sum - numberss[start]);
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    targetNum = target;
    numberss = numbers;
    dfs(0, 0);
    return answer;
}
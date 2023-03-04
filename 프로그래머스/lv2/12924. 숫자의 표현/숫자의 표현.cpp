#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 1;
    if (n == 1) return 1;
    for(int i = 1; i <= n/2 +1 ; i++) {
        // cout << i << '*' << '\n';
        int sum = i;
        for(int j = i + 1; j < n; j++) {
            sum += j;
            // cout << sum << '\n';
            if (sum >= n) {
                if (sum == n) answer += 1;
                break;
            }
        }
        // cout << "cnt :: " << answer << '\n';
    }
    return answer;
}
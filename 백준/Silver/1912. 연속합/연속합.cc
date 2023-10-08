// 수열 가장 크게 만들기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    vector<int> num;
    vector<int> prefix;
    int N;
    
    cin >> N;
    int k;
    for(int i = 0; i < N; i++) {
        cin >> k;
        num.push_back(k);
        if (i == 0) {
            prefix.push_back(k);
        } else {
            if (k > prefix[i-1]+k) {
                prefix.push_back(k);
            } else {
                prefix.push_back(prefix[i-1]+k);
            }
        }
    }

    sort(prefix.begin(), prefix.end(), [](int a, int b) {
        return a > b;
    });
    cout << prefix[0];
}
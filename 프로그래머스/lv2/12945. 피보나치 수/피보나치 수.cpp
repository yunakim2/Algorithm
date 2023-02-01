#include <string>
#include <vector>
#include <iostream>

using namespace std;

// int fibo(int n) {
//     if (n == 0 || n == 1) return n;
//     return fibo(n-1) + fibo(n-2) % 1234567;
// } 

int solution(int n) {
    vector<int> v;
    for(int i = 0; i <= n ; i++) {
        if (i == 0 || i == 1) v.emplace_back(i);
        else {
            v.emplace_back((v[i-1] + v[i-2]) % 1234567);     
        }
    }
    cout << v[n] << endl;
    return v[n];
}
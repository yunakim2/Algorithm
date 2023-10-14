#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>


using namespace std;

int N = 0;
int visited[10];
vector<char> v;
set<int> s;

bool isPrime(int num) {
    if (num == 0 || num == 1) return false;
    if (num == 2) return true;
    for (int k = 2; k * k  <= num; k++) {
        if (num % k == 0) return false;
    }
    return true;
}

void dfs(int start, int count, string str) {
    if (start == count) {
        if (str != "") {
            s.insert(stoi(str));
        }        
        return;
    }
    
    for(int k = 0; k < N; k++) {
        if (!visited[k]) {
            visited[k] = true;
            dfs(start +1, count, str + v[k]);
            visited[k] = false;
        }
    }
}

int solution(string numbers) {
    for(int i = 0; i <= numbers.length(); i++) {
        v.push_back(numbers[i]);
    }
    N = numbers.length();
    for(int i = 1; i <= numbers.length(); i++) {
        fill(visited, visited+10, 0);
        dfs(0, i, "");
    }
    
    int primeCount = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
         if (isPrime(*iter)) {
             primeCount += 1;
         }
    }
    
    return primeCount;
    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> word;
    int cnt = 1;
    word.emplace_back(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (i%n == 0) cnt += 1;
        if (words[i-1].back() != words[i].front()) {
            answer.emplace_back(i%n + 1);
            answer.emplace_back(cnt);
            return answer;
        }
        auto it = find(word.begin(), word.end(), words[i]);
        if (it != word.end()) {
            answer.emplace_back(i%n +1);
            answer.emplace_back(cnt);
            return answer;
        }
        word.emplace_back(words[i]);
    }
    
    answer.emplace_back(0);
    answer.emplace_back(0);
    return answer;
}
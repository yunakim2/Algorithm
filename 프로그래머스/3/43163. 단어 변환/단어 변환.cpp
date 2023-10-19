#include <bits/stdc++.h>

using namespace std;
int answer = 55;
int visited[55];
string word_arr[55];
int K;

bool checkingWord(string word, string new_word) {
    if (word.length() != new_word.length()) return false;
    int check = 0;
    for(int i = 0; i < word.length(); i++) {
        if (word[i] == new_word[i]) {
            check += 1;
        }
    }
    if (check == word.length()-1) return true;
    return false;
}

void dfs(string begin, string target, int cnt) {
    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }
    for(int i = 0; i < K; i++) {
        if(!visited[i] && checkingWord(begin, word_arr[i])) {
            visited[i] = 1;
            dfs(word_arr[i], target, cnt + 1);
            visited[i] = 0;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    K = words.size();
    for(int i = 0; i < words.size(); i++) {
        word_arr[i] = words[i];
    }
    dfs(begin, target, 0);
    return answer;
}
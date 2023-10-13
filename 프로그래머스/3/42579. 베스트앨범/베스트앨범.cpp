#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    for(int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), [](const auto &v1, const auto &v2){
        return v1.second > v2.second;
    });
    
    int start = 0;
    for(int i = 0; i < v.size(); i++) {
        vector<pair<int, int>> gen;
        for(int j = 0; j < plays.size(); j++) {
            if (v[i].first == genres[j]) {
                 gen.push_back(make_pair(plays[j], j));
            }
        }
        sort(gen.begin(), gen.end(), [](const auto &g1, const auto &g2) {
            if (g1.first == g2.first) {
                return g1.second < g2.second;
            }
            return g1.first > g2.first;
        });
        answer.push_back(gen[0].second);
        if (gen.size() >= 2) {
            answer.push_back(gen[1].second);
        }
    }
    
    
    return answer;
}
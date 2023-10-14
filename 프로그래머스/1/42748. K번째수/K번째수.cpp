#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    vector<int> v;
    for(const auto cmd : commands) {
        i = cmd[0];
        j = cmd[1];
        k = cmd[2];
        i--;
        j--;
        k--;
        vector<int>v(array.begin()+i, array.begin()+j+1);
        sort(v.begin(), v.end());
        answer.push_back(v[k]);
    }
    return answer;
}
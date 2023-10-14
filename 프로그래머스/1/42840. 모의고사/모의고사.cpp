#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {2,1,2,3,2,4,2,5};
    int arr3[] = {3,3,1,1,2,2,4,4,5,5};
    
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    for(int k = 0; k < answers.size(); k++) {
        if (answers[k] == arr1[k%5]) ans1 += 1;
        if (answers[k] == arr2[k%8]) ans2 += 1;
        if (answers[k] == arr3[k%10]) ans3 +=1;
    }
    int max_ans = 0;
    max_ans = max(ans1, ans2);
    max_ans = max(max_ans, ans3);
    
    vector<pair<int, int>> v;
    v.push_back({1, ans1});
    v.push_back({2, ans2});
    v.push_back({3, ans3});
    
  
    for(auto pp : v) {
        if (pp.second == max_ans) {
            answer.push_back(pp.first);
        }
    }
    return answer;
}
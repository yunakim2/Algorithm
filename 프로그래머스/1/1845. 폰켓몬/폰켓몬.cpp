#include <vector>
#include <cmath>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{   int N = nums.size();
    
    set<int> s;
   
    for(const auto &num : nums) {
        s.insert(num);        
    }

    if (s.size() >= N/2) {
        return N/2;
    } else {
        return s.size();        
    }
}
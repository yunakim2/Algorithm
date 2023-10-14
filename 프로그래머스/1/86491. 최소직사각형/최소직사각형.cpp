#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_width = 0;
    int max_height = 0;
    for(const auto &s : sizes) {
        if (s[0] > s[1]) {
            max_width = max(max_width, s[0]);
            max_height = max(max_height, s[1]);
        } else {
            max_width = max(max_width, s[1]);
            max_height = max(max_height, s[0]);
        }
    }
    return max_width * max_height;
}
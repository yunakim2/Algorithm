#include <string>
#include <deque>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string my_string) {
    string stringBuffer;
    vector<string> v;
    istringstream ss(my_string);
    while (getline(ss, stringBuffer, ' ')) {
        v.push_back(stringBuffer);
    }
    
    int total_sum = stoi(v[0]);
    
    for(int i = 0; i < v.size(); i++) {
        if (v[i] == "+") {
            total_sum += stoi(v[i+1]);
        } else if (v[i] == "-") {
            total_sum -= stoi(v[i+1]);
        }
    }
 

    return total_sum;
}
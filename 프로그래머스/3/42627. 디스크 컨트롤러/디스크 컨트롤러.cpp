#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), [](const auto &j1, const auto &j2){
        return j1[0] < j2[0];
    });
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    

    int time = 0;
    int total_work = 0;
    int total_size = jobs.size();
    while(pq.size() || jobs.size()) {
        while(jobs.size() && (jobs[0][0] <= time)) {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
         }
        if (pq.size() == 0) {
            time += 1;
        } else {
            time += pq.top()[1];
            total_work += (time - pq.top()[0]);
            pq.pop();
        }

    }
    return total_work / total_size;
}
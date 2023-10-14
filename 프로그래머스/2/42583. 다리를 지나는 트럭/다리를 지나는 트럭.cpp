#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> range_truck;
    queue<int> truck;
    for(const auto &t : truck_weights) {
        truck.push(t);
    }
    int time = 0;
    int truck_weight = 0;
    while(true) {
        if (range_truck.size() == 0 && truck.size() == 0) {
            break;
        }
        time ++;
        if (range_truck.size() > 0 && range_truck.front().second == bridge_length) {
            truck_weight -= range_truck.front().first;
            range_truck.pop();    
        }
        
        if (range_truck.size() <= bridge_length) {
            if (truck.size() >= 1) {
                if (truck.front() + truck_weight <= weight) {
                    range_truck.push({truck.front(), 0});
                    truck_weight += truck.front();
                    truck.pop();
                }
            }
        }
        
        queue<pair<int,int>> tmp_q;
        while(range_truck.size()) {
            tmp_q.push({range_truck.front().first, range_truck.front().second+1});
            range_truck.pop();
        }
        range_truck = tmp_q;
    }
    return time;
}
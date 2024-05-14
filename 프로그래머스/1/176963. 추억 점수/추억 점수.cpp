#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> maps;
    for(int i = 0; i < name.size(); i++) {
        maps.insert(make_pair(name[i], yearning[i]));
    }
    int sums = 0;
    for(int i = 0; i < photo.size(); i++) {
        sums = 0;
        for(auto item : photo[i]) {
            sums += maps[item];
        }
        answer.emplace_back(sums);
    }
    return answer;
}
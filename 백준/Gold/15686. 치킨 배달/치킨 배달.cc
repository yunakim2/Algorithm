#include <bits/stdc++.h>

using namespace std;
int N, M;
vector< pair<int, int> > v;
vector < pair<int, int> > q;
int check[15];
int min_cnt = 100004;

int cal(vector<pair <int, int> > chicken) {
    int sums = 0;
    for(int i = 0; i < v.size(); i++) {
        int cals = 55;
        pair<int, int> xy = v[i];
        int x = xy.second;
        int y = xy.first;
        // cout << x << y << '\n';
        for(int j = 0; j < chicken.size(); j++) {
            pair<int, int> nxy = chicken[j];
            int nx = nxy.second;
            int ny = nxy.first;
            // cout << nx << ny << '\n';
            cals = min(cals, (abs(nx-x) + abs(ny -y)));
            // cout << "cals" << cals << '\n';
        }
        sums += cals;
    }
    return sums;
}

void dfs(int start, int checking[], int cnt) {
    if (cnt == M) {
        vector<pair <int, int> > chicken;
        for(int i =0; i < q.size(); i++) {
            if (checking[i] == 1) {
                // cout << i << ' ';
                chicken.push_back(q[i]);
            }
        }
        min_cnt = min(min_cnt, cal(chicken));
        // cout << min_cnt;
        // cout << '\n';
        return;
    }
    for(int i = start; i < q.size(); i++) {
        if (checking[i] == 1) continue;
        checking[i] = 1;
        dfs(i, checking, cnt + 1);
        checking[i] = 0;
    }
    return;
}


int main() {
    cin >> N >> M;
    int temp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 1) {
                v.push_back({i, j});
            }
            if( temp == 2) {
                q.push_back({i, j});
            }
        }
    }

    dfs(0, check, 0);
    cout << min_cnt;
}
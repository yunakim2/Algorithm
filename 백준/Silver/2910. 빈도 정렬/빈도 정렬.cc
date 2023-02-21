#include <bits/stdc++.h>

using namespace std;

int N, C;
map<int, int> q;
vector<int> vv;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) {
    auto aa = find(vv.begin(), vv.end(), a.first);
    auto bb = find(vv.begin(), vv.end(), b.first);
    if (aa < bb) return true;
    else return false;
  }
  return a.second > b.second;
}

int main() {
  cin >> N >> C;
  string s;
  getline(cin, s);
  getline(cin, s);
  long long pos = 0;
  int token = 0;
  while ((pos = s.find(" ")) != string::npos) {
    token = stoi(s.substr(0, pos));
    if (q.find(token) != q.end()) {
      q[token] += 1; 
    } else {
      q.insert({token, 1});
      vv.push_back(token);
    }
    s.erase(0, pos + 1);
  }
  if (q.find(stoi(s)) != q.end()) {
    q[stoi(s)] += 1;
  } else {
    q.insert({stoi(s), 1});
    vv.push_back(token);
  }

  vector<pair<int, int>> v(q.begin(), q.end());
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) {
    for (int j = 0; j < i.second; j++) {
      cout << i.first << ' ';
    }
  }


}
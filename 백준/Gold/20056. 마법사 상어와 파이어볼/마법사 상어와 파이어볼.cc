#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int N;
int M;
int K;
struct info {
    // x - 행, y - 열
    int x, y;
    // d - 방향 , m - 질량, s - 속력
    int d, m,  s;
};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<info> atom;
vector<info> new_atom;

int arr[55][55];


// N 격자 크기, M 원자 개수, K 실험시간
// m 개 원자 질량, 방향, 속력, 초기 위치를 가짐
// 방향 - 상하좌우 대각선
// 초기 위치 - x: 행 (1 ~ n)
// y- 열 (1 ~ n)
// 격자 밖으로 나가게 되면 반대편으로 돌아오게 됨 !!!
// n번 열에서 오른쪽 이동시, 1번열 
// 1번 열에서 왼쪽 이동시, n번

void moveAtom(int num) {
    int x = atom[num].x;
    int y = atom[num].y;
    int d = atom[num].d;

    for(int i = 0; i < atom[num].s; i++) {
        x += dx[d];
        y += dy[d];

        if (x == -1) {
            x = N-1;
        }
        if (y == -1) {
            y = N-1;
        }
        if (x == N) {
            x = 0;
        }
        if (y == N) {
            y = 0;
        }
    }

    atom[num].x = x;
    atom[num].y = y;
}


void CombiAtom(int x, int y) {
    int totalM = 0;
    int totalS = 0;
    // 2-1. 같은 칸 원자는 각각 질량 + 속력을 모두 합한 하나의 원자로 합쳐진다
    // 2-2. 이후 합쳐진 원자 4개의 원자로 나눠짐
    // 2-3. 나눠진 원자 모두 해당칸 위치
    // 2-3-1. 질량 : 합쳐진 질량 / 5
    // 2-3-2. 속력 : 합쳐진 원자 속력 / 합쳐진 원자 개수

    vector<info> combi_atom;

    while(true) {
        bool checking = false;
        for(int i = 0; i < atom.size(); i++) {
            if (atom[i].x == x && atom[i].y == y){
                combi_atom.push_back(atom[i]);
                atom.erase(atom.begin() + i, atom.begin() + i + 1);
                checking = true;
                break;
            }
        }
        if(checking == false) break;
    }

    bool checkingD = true;
    int startD = combi_atom[0].d % 2;
    for(int i = 0; i < combi_atom.size() ; i++) {
        if(combi_atom[i].d % 2 != startD) {
            checkingD = false;
        }
        totalS += combi_atom[i].s;
        totalM += combi_atom[i].m;
    }

    if(checkingD) {
        startD = 0;
    } else {
        startD = 1;
    }

    for(int i = 0; i < 4; i++) {
        info tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.m = int(totalM / 5);
        tmp.s = int(totalS / combi_atom.size());

        // 2-3-3 방향 : 원자의 방향들이 모두 상하좌우 중 하나 /또는 대각선 중 하나면 -> 상하좌우 방향가짐
        // 아니면 대각선방향 가짐
        // 소숫점 아래수 버림
        tmp.d = startD;
        startD = (startD + 2) % 8;

        new_atom.push_back(tmp);
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    
    info tmp;
    for(int i = 0; i < M; i++) {
        cin >> tmp.x >> tmp.y >> tmp.m >> tmp.s >> tmp.d;
        tmp.x -= 1;
        tmp.y -= 1;
        atom.push_back(tmp);
    }

    for(int k = 0; k < K; k++) {
        // 1. 모든 원자 1초가 지날때 자신 속력만큼 이동
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                arr[i][j] = 0;
            }
        }

        vector< pair<int, int> > find_v;

        for(int i = 0; i < atom.size(); i++) {
            moveAtom(i);
            arr[atom[i].x][atom[i].y] += 1;
            if (arr[atom[i].x][atom[i].y] >=2) {
                if(find_if(find_v.begin(), find_v.end(), [&](pair<int, int> p){if (p.first == atom[i].x && p.second == atom[i].y) return true; else return false;}) == find_v.end()) {
                    find_v.push_back( {atom[i].x , atom[i].y});
                }
            }
        }

        // // cout << "이동 후 아톰들 \n";
        // for(int i = 0; i < atom.size(); i++) {
        //      // cout << " x : " <<  atom[i].x << " y: " << atom[i].y << "\n";
        //     // cout << " s : " << atom[i].s <<" d : "<< atom[i].d << " m : " << atom[i].m << "\n"; 
        // }

        new_atom.clear();
        new_atom.shrink_to_fit();
        // 2. 이동이 모두 끝난 뒤 하나의 칸에 2개 이상 원자가 있는 경우 합성 발생

        for(int i = 0; i < find_v.size(); i++) {
            CombiAtom(find_v[i].first, find_v[i].second);
        }

        for(int i = 0; i < atom.size(); i++) {
            new_atom.push_back(atom[i]);
        }

        atom.clear();
        atom.shrink_to_fit();
        // 3. 질량이 0인 원소는 소멸
        // ** 이동 과정 중, 원자가 만나는 경우는 합성 XXX
        for(int i = 0; i < new_atom.size(); i++) {
            if (new_atom[i].m > 0) {
                atom.push_back(new_atom[i]);
            }
        }

        int testCnt = 0;

        // cout << "살아남은 아톰들 \n";
        for(int i =0; i < atom.size(); i++) {
            testCnt += atom[i].m;
            // cout <<" ** i : " << i << "\n";
            // cout << " x : " <<  atom[i].x << " y: " << atom[i].y << "\n";
            // cout << " s : " << atom[i].s <<" d : "<< atom[i].d << " m : " << atom[i].m << "\n";
            // cout << "\n";
            // cout << "====================================\n";

        }

        // cout << k << " : " << testCnt << "\n";
        // cout << "\n";
    }


    int ans = 0;
    for(int i =0; i < atom.size(); i++) {
        ans += atom[i].m;
    }

    cout << ans;

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;

// 레일 값
int arr[10005];
int round = 1;
int saveCnt = 0;
vector<int> person;

void rotateMoving() {
    // 시계 방향 회전
    int last = arr[N*2-1];

    for(int i = N*2-2; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = last;

    for(int i = 0; i < person.size(); i++) {
        person[i] += 1;
    }

    person.erase(remove(person.begin(), person.end(), N), person.end());

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < N*2; i++) {
        cin >> arr[i];
    }
    // 길이가 N 무빙워크 안정성 테스트
    // 2N 개의 판으로 구성됨

    // 무빙워크 레일 시계 방향 회전함 
    // 1번칸부터 2N-1번 칸 -> 한번 회전시, 2N 칸 으로 위치함
    // 2N은 1번 칸 위치로 이동

    // 각 사람 1번칸에 올라서서 N 번칸에서 내리게 됨
    // 사람이 어떤 칸에 올라가거나 이동시, 그 칸 안정성 1 감소
    while(true) {
        // cout << "\n";
        // cout << "\n";

        // cout << "라운드 시작 - " << round << "\n";
        // 1. 무빙워크 1칸 회전
        rotateMoving();

        // cout << "무빙워크 한칸 회전 종료\n";
        for(int i = 0; i < N; i++) {
            // cout << arr[i] << " ";
        }
        // cout << "\n";
        // cout << "사람 위치\n";
        for(int i = 0; i < person.size(); i++) {
            // cout << "**" << i << " 번째 사람 : " << person[i] << "\n";
        }


        // 2. 가장 먼저 무빙워크에 올라간 사람이 회전하는 방향으로 한칸 이동할 수 있으면, 이동
        // 만약 앞칸에 사람있거나 안정성 0 인 경우 이동 X
        // 안정성이 0인 칸은 이동 불가능
        // 사람이 N 번칸 위치에 사람 있으면, 사람 내림 
        for(int i = 0; i < person.size(); i++) {
            int p_cur = person[i];
            // cout << p_cur << "**";
            if (p_cur +1 == N) {
                if(i < person.size()) {
                    person[i] = N;
                }
                continue;
            }
            if (p_cur < N*2 -1) {
                if (arr[p_cur+1] == 0) {
                    continue;
                }
            }
           
            if (find(person.begin(), person.end(), p_cur+1) != person.end()) {
                continue;
            }

            if(i < person.size() && p_cur+1 < 2*N -1) {
                person[i] = p_cur+1;
                arr[p_cur+1]-=1;
            }
        }

        // 3. 1번칸에 사람이 없고, 0이 아니라면 사람 한명 더 추가
        if (find(person.begin(), person.end(), 0) == person.end() && arr[0] > 0) {
            person.push_back(0);
            arr[0] -= 1;
        }

        // 4. 안정성이 0 인 칸이 k 개 이상이면 종료
        saveCnt = 0;
        for(int i = 0; i < N*2; i++) {
            if(arr[i] == 0) saveCnt += 1;
        }
        if (saveCnt >= K) {
            break;
        }


        person.erase(remove(person.begin(), person.end(), N), person.end());


        // cout << "사람 위치\n";
        for(int i = 0; i < person.size(); i++) {
            // cout << "**" << i << " 번째 사람 : " << person[i] << "\n";
        }
        // cout << "라운드 종료 ======\n";
        // cout << "Arr \n";
        for(int i = 0; i < N*2; i++) {
            // cout << arr[i] << " ";
        }
        // cout << "\n";

        // 아니면 1~4 반복
        // if(round == 4) break;
        
        round+=1;

    }



    // 1~4 과정이 한번의 실험일 경우, 과정 종료시 몇번째 실험인지 출력해라
    cout << round;

}
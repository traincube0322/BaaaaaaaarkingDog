// 9구역으로 자르고 재귀함수 호출.
#include <bits/stdc++.h>
using namespace std;

int board[2187][2187];
/// -1 0 1 의 개수 저장.
int cnt[3];

// x,y 부터 N*N 크기의 박스를 검사.
// 박스 내부가 다 같으면 true, 아니면 false 반환
bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++) {
        for(int j = y; j < y+n; j++) {
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void ans(int x, int y, int z) {
    // 모두 같은 값이면, cnt에 더해줌.
    if(check(x, y, z)) {
        cnt[board[x][y] + 1] += 1;
        return;
    }
    // 아니라면, 9개의 구역으로 나눠서 다시 검사.
    int n = z / 3;
    for(int i = 0; i < 3;i ++) {
        for(int j = 0; j < 3; j++){
            ans(x + (i*n), y + (j*n), n);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    ans(0, 0, N);

    for(int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }

}
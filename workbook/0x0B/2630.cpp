#include <bits/stdc++.h>
using namespace std;

int board[128][128];

int cnt[2];

bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++) {
        for(int j = y; j < y + n; j++) {
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void ans(int x, int y, int z) {
    if(check(x, y, z)) {
        cnt[board[x][y]]++;
        return;
    }
    int n = z/2;
    for(int i =0 ; i < 2; i ++) {
        for(int j = 0; j < 2; j++) {
            ans(x + i * n, y + j*n, n);
        }
    }
}
 
int main() {
    int N;
    cin >> N;
    for(int i =0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    ans(0,0,N);
    for(int i = 0; i < 2; i++) {
        cout << cnt[i] << "\n";
    }
}
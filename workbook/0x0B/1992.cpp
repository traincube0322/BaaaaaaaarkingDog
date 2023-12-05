#include <bits/stdc++.h>
using namespace std;

string board[64];

// x,y 부터 n*n의 보드가 같은지 확인함.
bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++) {
        for(int j = y; j < y+n; j++) {
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void ans(int x, int y, int z) {
    if(check(x,y,z)) {
        cout << board[x][y];
        return;
    }
    int n = z / 2;
    cout << "(";
    for(int i = 0; i < 2;i++) {
        for(int j = 0; j < 2; j++) {
            ans(x + i * n, y + j * n, n);
        }
    }
    cout << ")";
}

int main() {
    int N;
    string tmp;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }


    ans(0,0,N);

}
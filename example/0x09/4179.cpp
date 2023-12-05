#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1000];

int dist1[1000][1000]; // 불
int dist2[1000][1000]; // 지훈

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    //행, 열.
    int R, C;
    queue<pair<int, int> > Q1; // 불
    queue<pair<int, int> > Q2; // 지훈
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        fill(dist1[i], dist1[i] + C, -1);
        fill(dist2[i], dist2[i] + C, -1);
    }

    for(int i = 0; i < R; i++){
        cin >> board[i];
    }

    // 불과 지훈이의 위치를 찾아 Q에 푸쉬.
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'F') {
                Q1.push({i,j});
                dist1[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                Q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }

    while(!Q1.empty()) {
        auto cur = Q1.front();
        Q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            // 다음 탐색할 칸이 벽이거나, 탐색한 공간이면, (dist가 0이상)
            if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }

    while(!Q2.empty()) {
        auto cur = Q2.front();
        Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 탈출 성공
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            // 벽이거나 불이 먼저 붙은 칸이면 못감.
            if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }
    // 탈출 실패
    cout << "IMPOSSIBLE";

}
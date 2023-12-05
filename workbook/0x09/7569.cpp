#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Z 

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int board[100][100][100];
int dist[100][100][100];

int main() {
    int M, N, H;
    int ans = 0;
    queue<tuple<int, int, int> > Q;
    
    // 가로 M 세로 N 높이 H
    // 안익은 토마토 dist = - 1
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> board[j][k][i];
                if(board[j][k][i] == 1) Q.push({j,k,i});
                if(board[j][k][i] == 0) dist[j][k][i] = -1;

            }
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX,curY,curZ) = cur;
        for(int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            
            if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
            // 익었거나 빈 곳 패스
            if(dist[nx][ny][nz] >= 0) continue;
            Q.push({nx,ny,nz});
            
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if(dist[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans;


}
#include <bits/stdc++.h>
using namespace std;

int board[51][51];
bool vis[51][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int T, N, M, K, x, y, cnt;
    queue<pair <int, int>> Q;

    cin >> T;
    while(T--) {
        cnt = 0;
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }

        //모든 칸을 하나씩 체크하면서 bfs수행
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                else {
                    cnt++;
                    Q.push({i,j});
                    vis[i][j] = 1;
                    while(!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        for(int dir = 0; dir < 4; dir++) {
                            int nx = cur.first+dx[dir];
                            int ny = cur.second+dy[dir];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                
                }
            }
        }

        for(int i =0 ;i < N; i++) {
            fill(board[i], board[i] + M, 0);
            fill(vis[i], vis[i] + M, 0);
        }
    

        cout << cnt << "\n";

    }

}
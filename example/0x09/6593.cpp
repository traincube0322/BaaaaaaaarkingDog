#include <bits/stdc++.h>
using namespace std;

char board[30][30][30];

int dist[30][30][30];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main() {
    int L, R, C;
    

    char tmp;


    while(true) {
        queue<tuple<int, int, int> >Q;
        cin >> L >> R >> C;
        if(!L && !R && !C) return 0;
        
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    cin >> tmp;
                    board[j][k][i] = tmp;
                    if(tmp == 'S') {
                        dist[j][k][i] = 0;
                        Q.push({j,k,i});
                    }
                    else dist[j][k][i] = -1;
                }

            }
        }

        bool TF = false;
        int ans;
        int aX,aY,aZ;
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if(TF) break;
            ans++;
            int curX, curY, curZ;
            tie(curX,curY,curZ) = cur;
            for(int dir = 0; dir < 6; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];

                if(nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
                if(dist[nx][ny][nz] >= 0 || board[nx][ny][nz] == '#') continue;
                if(board[nx][ny][nz] == 'E') {
                    TF = true;
                    aX = nx;
                    aY = ny;
                    aZ = nz;
                }
                Q.push({nx,ny,nz});
                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                
            }

        }

        ans = dist[aX][aY][aZ];
        if(TF) cout << "Escaped in " << ans << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}
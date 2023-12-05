#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


string board[1001];
int fire[1001][1001];
int sang[1001][1001];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main() {
    int T, w, h;
    queue<pair<int, int> > fire_Q;
    queue<pair<int,int > > sang_Q;

    cin >> T;
    while(T--) {
        cin >> w >> h;

        for(int i = 0; i < h; i++) {
            fill(fire[i], fire[i] + w, -1);
            fill(sang[i], sang[i] + w, -1);
        }

        for(int i = 0; i < h; i++) {
            cin >> board[i];

        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {

                if(board[i][j] == '*') {
                    fire_Q.push({i,j});
                    fire[i][j] = 0;
                }
                if(board[i][j] == '@') {
                    sang_Q.push({i,j});
                    sang[i][j] = 0;
                }
            }
        }


        //불에 대한 BFS
        while(!fire_Q.empty()) {
            auto cur = fire_Q.front();
            fire_Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                // 다음 칸이 벽이거나, 이미 갔던 칸이면 스킵.
                if(fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                fire_Q.push({nx,ny});
            }
        }


        bool TF = false;
        int ans;
        while(!sang_Q.empty()) {
            auto cur = sang_Q.front();
            sang_Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                // 탈출 성공.
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) {
                    TF = true;
                    ans = sang[cur.X][cur.Y] + 1;
                }
                if(TF) break;
                if(sang[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                // 불이 먼저 붙은 칸에 못감.
                if(fire[nx][ny] != -1 && fire[nx][ny] <= sang[cur.X][cur.Y] + 1) continue;
                sang[nx][ny] = sang[cur.X][cur.Y] + 1;
                sang_Q.push({nx,ny});
            }
        }

        if(TF) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
        
    }

}
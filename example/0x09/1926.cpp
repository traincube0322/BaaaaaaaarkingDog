#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[500][500];
bool vis[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt = 0, max = 0, tmp;
    queue<pair<int, int>> Q;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 타일을 다 탐색, 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || board[i][j] != 1) continue;
            // i, j 방문, BFS 시작.
            else {
                tmp = 0;
                cnt++;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    tmp++;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        // 존재하지 않는 위치 제외
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        // 이미 방문했거나, 0인 위치 제외
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                if (tmp > max) max = tmp;
            }
        }
    }


    cout << cnt << "\n" << max;
   
}
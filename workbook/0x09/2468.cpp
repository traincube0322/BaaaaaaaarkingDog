#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[100][100];
bool vis[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int N, tmp;
    int maxH = 0, minH = 101;
    queue<pair<int, int> >Q;
    int ans = 1;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j< N; j++) {
            cin >> tmp;
            board[i][j] = tmp;
            maxH = max(maxH, tmp);
            minH = min(minH, tmp);
        }
    }

    // 물에 잠기는 높이를  H라는 기준으로 잡음.
    for(int H = minH; H < maxH; H++) {
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            fill(vis[i], vis[i]+N, 0);
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(vis[i][j] == 1 || board[i][j] <= H) continue;
                Q.push({i,j});
                vis[i][j] = 1;
                cnt++;
                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] <= H) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;

}

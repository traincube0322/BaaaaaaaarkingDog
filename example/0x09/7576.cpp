#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int tomato[1000][1000];
int dist[1000][1000];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int M, N;
    queue<pair <int, int>> Q;
    cin >> M >> N;


// 초기세팅 >> 익은 토마토 : 1, 빈 곳 : 0, 안익은 토마토 : dist = -1 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) Q.push({i, j});
            if(tomato[i][j] == 0) dist[i][j] = -1;
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
            
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 안익은 토마토 발견.
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;


}
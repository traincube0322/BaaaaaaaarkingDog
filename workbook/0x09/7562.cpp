#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[300][300];

// 나이트가 이동할 수 있는 칸 8개
int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    int T, l, x, y;
    queue<pair<int, int > >Q;
    cin >> T;

    while(T--) {
        
        cin >> l;
        for(int i = 0; i < l; i++) {
            fill(dist[i], dist[i] + l, -1);
        }
        cin >> x >> y;
        Q.push({x, y});
        dist[x][y] = 0;
        cin >> x >> y;
        
        
        int ans = 0;
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
                // 목표지점 도달 시 저장.
                if(nx == x && ny == y) ans = dist[nx][ny];
            }
        }
        cout << ans << "\n";

    }
}
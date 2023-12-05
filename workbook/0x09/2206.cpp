#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1000][1000];
int dist[1000][1000];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int N, M;
    char tmp;
    int ans = INT_MAX;
    queue<pair<int, int> >Q;
    cin >> N >> M;
    for(int i = 0; i < N; i++) { 
        for(int j = 0; j < M; j++) {
            cin >> tmp;
            board[i][j]= tmp - '0';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == N-1 && j == M-1) break;
            // 부술 벽 선정 : 보드가 1일때 bfs 시작.
            if(board[i][j] == 0) continue;
            for(int i = 0; i < N; i++) {
                fill(dist[i], dist[i] + M, -1);
            }
            board[i][j] = 0;
            Q.push({0,0});
            dist[0][0] = 0;
            
            //bfs 시작
            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny <0 || nx >= N || ny >= M) continue;
                    if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
                    Q.push({nx,ny});
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                }
            }

            board[i][j] = 1;
            // bfs로 도착점까지 가지 못한 경우.
            if(dist[N-1][M-1] == -1) continue;
            ans = min(ans, dist[N-1][M-1]);
            cout << "ans : " << ans << "\n";
            
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans + 1;
}
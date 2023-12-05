#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[100][100];
// vis 대신 각 타일마다의 거리를 나타내는 dist배열 사용, 0이면 방문하지 않은 것.
int dist[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    queue<pair<int, int>> Q;
    int N, M;
    string str;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    Q.push({0,0});
    dist[0][0] = 0;
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] > 0 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[N-1][M-1] + 1;


}
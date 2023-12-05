#include <bits/stdc++.h>
using namespace std;

char board[100][100];
bool vis[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int N;
    string str;
    int ans1 = 0, ans2 = 0;
    char color;
    queue<pair<int, int>> Q;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            board[i][j] = str[j];
        }
    }

    // 적록색맹 아닌 경우.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            //방문한 타일 스킵.
            if(vis[i][j] != 0) continue;
            else {
                color = board[i][j];
                Q.push({i,j});
                vis[i][j] = 1;
                ans1++;
                while(!Q.empty()) {

                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        // 방문했거나, 같은색이 아닐 경우 스킵.
                        if(vis[nx][ny] == 1 || board[nx][ny] != color) continue;

                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }    
    }
    cout << ans1 << " ";
    for(int i = 0; i < N; i++ ) {
        fill(vis[i], vis[i] + N, 0);
    }
    // 적록생맹인 경우.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            //방문한 타일 스킵.
            if(vis[i][j] != 0) continue;
            else {
                color = board[i][j];
                Q.push({i,j});
                vis[i][j] = 1;
                ans2++;
                while(!Q.empty()) {

                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        // 방문했거나, 같은색이 아닐 경우 스킵.
                        if(vis[nx][ny] == 1) continue;
                        if(color == 'B') {
                            if(board[nx][ny] != color) continue;
                        }
                        else {
                            if(board[nx][ny] == 'B') continue;
                        }
                        

                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }    
    }
    cout << ans2;

}
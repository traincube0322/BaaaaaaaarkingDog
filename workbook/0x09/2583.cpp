#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second



int board[100][100];
bool vis[100][100];
// board 가 0 일때 영억 찾기 해야함.

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int M, N, K;
    int x1,x2,y1,y2;
    int cnt = 0;
    int area = 0;
    vector<int> ans;
    queue<pair<int, int> > Q;

    cin >> M >> N >> K;
    while(K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                board[i][j] = 1;
            }
        }
    }

    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            Q.push({i,j});
            vis[i][j] = 1;
            area = 0;
            cnt++;
            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny <0 || nx >= M || ny >= N) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            ans.push_back(area);
        }
    }

    sort(ans.begin(), ans.end());
    cout << cnt << "\n";
    for(auto v : ans) {
        cout << v << " ";
    }

}
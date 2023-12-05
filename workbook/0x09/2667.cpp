#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[25][25];
bool vis[25][25];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int N;
    string str;
    queue<pair<int, int> > Q;
    vector<int> ans;
    int cnt = 0, area;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            Q.push({i,j});
            vis[i][j] = 1;
            cnt++;
            area = 0;
            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
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
        cout << v << "\n";
    }

}
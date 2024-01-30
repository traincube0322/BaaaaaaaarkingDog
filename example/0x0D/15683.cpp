#include <bits/stdc++.h>
using namespace std;

int N, M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board1[8][8];
int board2[8][8];
vector<pair<int, int>> cctv;

// Out Of Band
bool OOB(int a, int b)
{
	return a < 0 || a >= N || b < 0 || b >= M;
}

// (x,y) 에서 dir 방향으로 진행하며 벽을 만나기 전까지 모든 빈칸을 7로 바꿈.
void upd(int x, int y, int dir)
{
	dir %= 4;
	while (1)
	{
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; // 범위 벗어나거나, 벽 만나면 중단.
		if (board2[x][y] != 0) continue; // 다른 cctv는 바꾸지 않고 통과.
		board2[x][y] = 7;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int mn = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({i, j});
			if (board1[i][j] == 0)
				mn++;
		}
	}
	 // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미한다.
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
	{
		// board2 초기화
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		// cctv를 순서대로 확인.
		for (int i = 0; i < cctv.size(); i++)
		{
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (board1[x][y] == 1)
				upd(x, y, dir);
			else if (board1[x][y] == 2)
			{
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (board1[x][y] == 3)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board1[x][y] == 4)
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
			int val = 0;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					val += (board2[i][j] == 0);
			mn = min(mn, val);
		}
	}
	cout << mn;	
	
}
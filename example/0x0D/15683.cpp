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
int main()
{
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
	
	
}
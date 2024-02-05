#include <bits/stdc++.h>
using namespace std;

int N;
int board1[20][20];
int board2[20][20];

void rotate()
{
	int tmp[20][20];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board2[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board2[i][j] = tmp[N - 1 - j][i];
}

void tilt(int dir)
{
	while (dir--) rotate();
	for (int i = 0; i < N; i++)
	{
		// 한 행씩 왼쪽으로 기울인다고 생각.
		int tilted[20]= {};
		int idx = 0;
		for (int j = 0; j < N; j++)
		{
			// 0 인 경우, idx증가시키지 않고 그냥 스킵.
			if (board2[i][j] == 0) continue;
			// board2[i][j]가 0이 아니고, tilted에 아무것도 들어가있지 않으면 삽입.
			if (tilted[idx] == 0)
				tilted[idx] = board2[i][j];
			// tilted에 들어가있는 수가 보드에 적힌 수와 같으면 수 2배하고 다음자리로 이동.
			else if (tilted[idx] == board2[i][j])
				tilted[idx++] *= 2;
			// 다음 자리에 수 집어넣기.
			else
				tilted[++idx] = board2[i][j];
		}
		// tilted에 만들어놓은 배열 board2로 복사.
		for (int j = 0; j < N; j++)
			board2[i][j] = tilted[j];
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board1[i][j];
	int mx = 0;
	// 1024 = 4^5 기울이는 방향 정하기.
	for (int tmp = 0; tmp < 1024; tmp++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mx = max(mx, board2[i][j]);
	}
	cout << mx << "\n";
}
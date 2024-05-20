#include <bits/stdc++.h>
using namespace std;

int table[20][20];

/*
2가 윗면, 5가 아랫면.
  0
1 2 3
  4
  5
*/
int dice[6];

// 1 : east, 2 : west, 3 : north, 4 : south
int N, M, x, y;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

bool is_valid(int dir)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= M || ny < 0 || ny >= N)
		return false;
	return true;
}

void dice_roll(int dir)
{
	if (!is_valid(dir))
		return ;
	x += dx[dir];
	y += dy[dir];
	int tmp;
	if (dir == 1)
	{
		tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	if (dir == 2)
	{
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = tmp;
	}
	if (dir == 3)
	{
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = tmp;
	}
	if (dir == 4)
	{
		tmp = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[5];
		dice[5] = tmp;
	}
	if (table[y][x] == 0)
		table[y][x] = dice[5];
	else
	{
		dice[5] = table[y][x];
		table[y][x] = 0;
	}
	cout << dice[2] << "\n";
}

int main()
{
	int K;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> table[i][j];
	int dir;
	while (K--)
	{
		cin >> dir;
		dice_roll(dir);
	}
}
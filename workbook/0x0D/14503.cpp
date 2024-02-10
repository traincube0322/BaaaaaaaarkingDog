#include <bits/stdc++.h>
using namespace std;

int N, M;

int room[50][50];
int clean[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cur_row, cur_col, cur_dir;
	cin >> N >> M;
	cin >> cur_row >> cur_col >> cur_dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];
	
}
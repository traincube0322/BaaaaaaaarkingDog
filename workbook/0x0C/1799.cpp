#include <bits/stdc++.h>
using namespace std;

int N, ans, cnt;

int board[10][10];
int vishop[10][10];

vector<int> v;
list<int> l;

int	is_valid(int cur)
{
	int cur_row = cur / N;
	int cur_col = cur % N;
	for (auto i : l)
	{
		int	row = i / N;
		int	col = i % N;			
		
		if (cur_row + cur_col == row + col && vishop[row][col])
			return 0;
		if (cur_row - cur_col == row - col && vishop[row][col])
			return 0;
	}
	return 1;
}

void solve_puzzle(int depth)
{
	if (depth == N * N)
	{
		ans = max(ans, cnt);
		return;
	}
	int row = depth / N;
	int col = depth % N;
	if (board[row][col])
	{
		if (is_valid(depth))
		{
			vishop[row][col] = 1;
			l.push_back(depth);
			cnt++;
			solve_puzzle(depth + 1);
			cnt--;
			l.pop_back();
		}
		vishop[row][col] = 0;
		solve_puzzle(depth + 1);
	}
	else solve_puzzle(depth + 1);
	vishop[row][col] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	solve_puzzle(0);
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string field[12];

bool visited[12][6];

void reset_vis()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visited[i][j] = false;
}

// 뿌요를 터트릴 수 있으면 터트리고 true반환.
bool is_puyo()
{
	reset_vis();
	queue<pair<int, int>> Q;
	bool is_del = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (field[i][j] != '.' && visited[i][j] == 0)
			{
				vector<pair<int, int>> puyo;
				char tmp = field[i][j];
				Q.push({i, j});
				visited[i][j] = 1;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					puyo.push_back({cur.first, cur.second});
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
							continue;
						if (field[nx][ny] == '.' || visited[nx][ny] == 1)
							continue;
						if (tmp != field[nx][ny])
							continue;
						Q.push({nx, ny});
						visited[nx][ny] = true;
					}
				}
				if (puyo.size() >= 4)
				{
					for (auto v : puyo)
						field[v.first][v.second] = '.';
					is_del = true;
				}
			}
		}
	}
	if (is_del)
		return true;
	return false;
}

void fall()
{
	for (int i = 0; i < 6; i++)
	{
		vector<char> v;
		for (int j = 11; j >= 0; j--)
		{
			if (field[j][i] != '.')
				v.push_back(field[j][i]);
		}
		for (int j = 0; j < 12; j++)
		{
			if (j < v.size())
				field[11 - j][i] = v[j];
			else
				field[11 - j][i] = '.';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		cin >> field[i];
	int cnt = 0;
	while (is_puyo())
	{
		fall();
		cnt++;
	}
	cout << cnt << "\n";
}
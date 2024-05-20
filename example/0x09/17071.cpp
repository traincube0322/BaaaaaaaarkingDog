#include <bits/stdc++.h>
using namespace std;

bool visited[500001];
int sister[500001];

int main()
{
	int N, K;
	queue<pair<int, int>> Q;
	fill(sister, sister + 500001, -1);
	cin >> N >> K;
	int cnt = 0;
	for (int i = K; i <= 500000; i += cnt)
	{
		sister[i] = cnt;
		cnt++;
	}
	Q.push({N, 0});
	visited[N] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int loc = cur.first;
		int time = cur.second;
		if (sister[loc] == time)
		{
			cout << time;
			return 0;
		}
		for (int next : {loc - 1, loc + 1, 2 * loc})
		{
			if (next < 0 | next > 500000)
				continue;
			if (visited[next])
				continue;
			if (sister[next] == (time + 1))
			{
				cout << sister[next];
				return (0);
			}
			Q.push({next, time + 1});
			visited[next] = 1;
		}
	}
	cout << -1;
}
#include <bits/stdc++.h>
using namespace std;

int city[50][50];
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back({i, j});
			if (city[i][j] == 2) chicken.push_back({i, j});
		}
	}
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - M, 0);
	// 뒤에서부터 M개를 1로 채우고, 나머진 0으로 채워서 1일 때만, 거리구함.
	int mn = 2147483647;
	do 
	{
		int dist = 0;
		// 집마다, 치킨집 하나씩 대조하는데, brute[i]가 1인 치킨집만 검사.
		for (auto h : house)
		{
			int tmp = 2147483647;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (brute[i] == 0) continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	}
	while (next_permutation(brute.begin(), brute.end()));
	cout << mn << "\n";
}
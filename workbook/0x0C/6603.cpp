#include <bits/stdc++.h>
using namespace std;

int result[6];
int k;

void	lotto(vector<int> &v, int cur, int idx)
{
	if (cur == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i <= k - 6 + cur; i++)
	{
		result[cur] = v[i];
		lotto(v, cur + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		vector<int> v;
		int num;
		for (int i = 0; i < k; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		lotto(v, 0, 0);
		cout << "\n";
	}
	return 0;
}
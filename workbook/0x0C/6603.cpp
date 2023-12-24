#include <bits/stdc++.h>
using namespace std;

void	lotto(vector<int> &v, int k)
{
	for (auto i : v)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
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
		lotto(v, k);
	}
	return 0;
}
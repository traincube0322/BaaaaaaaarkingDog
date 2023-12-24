#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

void NM(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (k > 0 && i < arr[k - 1])
			continue;
		arr[k] = i;
		NM(k + 1);
	}
}

int	main()
{
	cin >> n >> m;
	NM(0);
}
#include <bits/stdc++.h>
using namespace std;

int 	k;
int 	arr[6];
int		lotto[13];

void	result(int depth, int cur)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = cur; i < k; i++)
	{
		arr[depth] = lotto[i];
		result(depth + 1, i + 1);
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
		for (int i = 0; i < k; i++)
			cin >> lotto[i];
		result(0, 0);
		cout << "\n";
	}
	return 0;
}
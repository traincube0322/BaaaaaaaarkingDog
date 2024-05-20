#include <bits/stdc++.h>
using namespace std;

long dp[105] = {1, 1, 1, 2, 2, 3, };

int main()
{
	int T;
	cin >> T;

	for (int i = 6; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int n;
	while (T--)
	{
		cin >> n;
		cout << dp[n - 1] << "\n";
	}
}
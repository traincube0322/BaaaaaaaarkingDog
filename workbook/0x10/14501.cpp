#include <bits/stdc++.h>
using namespace std;

int T[16];
int P[16];
int dp[16];

// dp[i] 
// i 번째 날, 상담했을 때, 얻을 수 있는 수익.


int main()
{
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];

	for (int i = 1; i <= N; i++)
	{
		if (i + T[i] <= N + 1)
			dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1]);
		else
			dp[i] = dp[i + 1];
	}
	cout << *max_element(dp, dp + N);
}
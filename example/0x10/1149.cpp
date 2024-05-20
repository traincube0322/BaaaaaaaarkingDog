#include <bits/stdc++.h>
using namespace std;

int N;

// dp[i][color] i 번째 집을 color로 칠하는 경우에 비용의 최솟갑값.
int dp[1001][3];
int r[1001], g[1001], b[1001];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> r[i] >> g[i] >> b[i];
	dp[1][0] = r[1];
	dp[1][1] = g[1];
	dp[1][2] = b[1];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}
	cout << min({dp[N][0], dp[N][1], dp[N][2]});
}
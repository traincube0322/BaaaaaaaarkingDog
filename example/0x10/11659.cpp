#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int tmp;
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		dp[i] = dp[i -1] + tmp;
	}
	int begin, end;
	while (M--)
	{
		cin >> begin >> end;
		cout << dp[end] - dp[begin - 1] << '\n';
	}
}
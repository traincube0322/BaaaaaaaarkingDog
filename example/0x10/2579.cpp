#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[301];
	int dp[301][3];
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	if (N == 1)
	{
		cout << arr[1];
		return 0;
	}
	// 첫 번째 계단을 1번만에 올라갔을 때의 점수.
	dp[1][1] = arr[1];
	dp[1][2] = 0;
	dp[2][1] = arr[2];
	dp[2][2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	cout << max(dp[N][1], dp[N][2]);
}
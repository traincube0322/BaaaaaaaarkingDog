#include <bits/stdc++.h>
using namespace std;
#define S first
#define W second

int N;
//내구도, 무게
pair<int, int> arr[8];
int ans;

int borken_all_except(int egg)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == egg)
			continue;
		if (arr[i].S < 1)
			cnt++;
	}
	return cnt == N - 1;
}

void func(int cur)
{
	if (cur == N)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (arr[i].S < 1)
				cnt++;
		ans = max(ans, cnt);
		return;
	}
	// 손에든 계란이 깨진경우. 다음 계란 쥐기
	if (arr[cur].S < 1)
		func(cur + 1);
	else
	{
		for (int i = 0; i < N; i++)
		{
			// 손에든 계란차례 혹은, 때릴려는 계란이 이미 부셔진 경우.
			if (i == cur || arr[i].S < 1)
				continue;
			arr[cur].S -= arr[i].W;
			arr[i].S -= arr[cur].W;
			func(cur + 1);
			arr[cur].S += arr[i].W;
			arr[i].S += arr[cur].W;
		}
		if (borken_all_except(cur))
			func(cur + 1);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, w;
		cin >> s >> w;
		arr[i] = {s, w};
	}
	func(0);
	cout << ans;
}
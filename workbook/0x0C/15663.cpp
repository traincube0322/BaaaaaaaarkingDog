#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8];
int result[8];
bool isused[8];

void func(int cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		if (!isused[i] && tmp != num[i])
		{
			isused[i] = true;
			result[cur] = num[i];
			tmp = result[cur];
			func(cur + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	func(0);
}
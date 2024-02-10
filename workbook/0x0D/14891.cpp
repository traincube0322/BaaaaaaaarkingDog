#include <bits/stdc++.h>
using namespace std;

string gear[4];

// 기어의 출발점은 start, 현재 Num의 기어를 dir방향으로 돌려라.
void run(int start, int num, int dir)
{
	if (num < 0 || num > 3)
		return;
	// 왼쪽으로 진행
	if (start >= num && num > 0)
	{
		if (gear[num][6] != gear[num - 1][2])
			run(start, num - 1, -dir);
	}
	// 오른쪽으로 진행
	if (start <= num  && num < 3)
	{
		if (gear[num][2] != gear[num + 1][6])
			run(start, num + 1, -dir);
	}
	if (dir == 1)
		rotate(gear[num].begin(), gear[num].end() - 1 ,gear[num].end());
	if (dir == -1)
		rotate(gear[num].begin(), gear[num].begin() + 1 ,gear[num].end());
}

// index 0 : 12'o clock
// index 2 : 3'o clock, 6 : 9'o clock
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
		cin >> gear[i];
	int K;
	cin >> K;
	while(K--)
	{
		int num, dir;
		cin >> num >> dir;
		run(num - 1, num - 1, dir);
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
		if (gear[i][0] == '1') ans += (1 << i);
	cout << ans << "\n";
}

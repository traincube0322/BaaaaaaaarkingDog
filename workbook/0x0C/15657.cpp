#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8];
int result[8];

void func(int cur, int idx)
{
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = idx; i < N; i++)
	{
		result[cur] = arr[i];
		func(cur + 1, i);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	func(0, 0);
}
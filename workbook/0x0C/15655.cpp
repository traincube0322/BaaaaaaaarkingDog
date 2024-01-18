#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8];
int result[8];
int visited[8];

void func(int cur, int idx)
{
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = idx; i <= N - (M - cur); i++)
	{
		if (!visited[i])
		{
			result[cur] = arr[i];
			visited[i] = 1;
			func(cur + 1, i + 1);
			visited[i] = 0;
		}
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
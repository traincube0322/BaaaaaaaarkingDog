#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[8];
int result[8];

void func(int cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = 0; i < N; i++)
	{
		result[cur] = arr[i];
		func(cur + 1);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	func(0);
}
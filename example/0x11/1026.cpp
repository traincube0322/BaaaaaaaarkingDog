#include <bits/stdc++.h>
using namespace std;

int A[50];
int B[50];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A, A + N, greater<int>());
	sort(B, B + N, less<int>());
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += A[i] * B[i];
	cout << ans << "\n";
}
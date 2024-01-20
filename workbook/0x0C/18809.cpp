#include <bits/stdc++.h>
using namespace std;

int N, M;
// 0 : 호수 | 1 : 배양액 뿌리기 가능 | 2 : 배양액 못뿌림.
int garden[50][50];
int isused[50][50];

int ans;

void solve()
{
	
}

void bfs_G()
{

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int G, R;

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> garden[i][j];
	solve();
	cout << ans;
	
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v;
	int N;
	cin >> N;
	int tmp;
	while (N--)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), greater<int>());
	int weight = 0;
	int cnt = 1;
	for (int i : v)
		weight = max(weight, i * cnt++);
	cout << weight << "\n";
}
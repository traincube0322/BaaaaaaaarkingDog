#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[15];
char passwd[15];

int cnt_vowel;
int cnt_consonants;

int is_vowel(char c)
{
	for (char a : {'a', 'e', 'i', 'o', 'u'})
		if (a == c)
			return 1;
	return 0;
}

void make_passwd(int cur, int idx)
{
	if (cur == L)
	{
		if (cnt_vowel < 1 || cnt_consonants < 2)
			return;
		for (int i = 0; i < L; i++)
			cout << passwd[i];
		cout << "\n";
		return;
	}
	for (int i = idx; i <= C - L + cur; i++)
	{
		if (is_vowel(arr[i]))
			cnt_vowel++;
		else cnt_consonants++;
		passwd[cur] = arr[i];
		make_passwd(cur + 1, i + 1);
		if (is_vowel(arr[i]))
			cnt_vowel--;
		else cnt_consonants--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);
	make_passwd(0, 0);
}
#include <bits/stdc++.h>
using namespace std;

int freq[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s;
    cin >> s;
    for(auto c : s) {
        freq[c-'0']++;
    }
    freq[6] = (freq[6] + freq[9] + 1) / 2;
    for(int i = 0; i < 9; i++) {
        ans = max(ans, freq[i]);
    }
    cout << ans;
}
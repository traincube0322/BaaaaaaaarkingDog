#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, cnt = 0;
    vector<int> coin;
    cin >> N >> K;
    int tmp;
    while(N--) {
        cin >> tmp;
        coin.push_back(tmp);
    }
    for(int i = coin.size() - 1; i >= 0; i--) {
        cnt += K / coin[i];
        K %= coin[i];
    }
    cout << cnt;
}
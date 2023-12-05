#include <bits/stdc++.h>
using namespace std;

int main() {
    // index, value
    stack<pair<int, int> > S;
    int N, num;
    long long ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(S.empty()) S.push({i, num});
        else {
            while(!S.empty() && S.top().second <= num) {
                ans += i - S.top().first - 1;
                S.pop();
            }
            S.push({i, num});
        }
    }
    num = 1000000001;
    while(!S.empty() && S.top().second < num) {
        ans += N - S.top().first - 1;
        S.pop();
    }

    cout << ans;
}
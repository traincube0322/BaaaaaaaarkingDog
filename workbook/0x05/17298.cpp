#include <bits/stdc++.h>
using namespace std;

int ans[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // index, value
    stack <pair<int, int> > S;
    
    int N, num;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(S.empty()) S.push({i, num});
        else {
            while(!S.empty() && S.top().second < num) {
                ans[S.top().first] = num;
                S.pop();
            }
            S.push({i, num});
        }

    }
    while(!S.empty()) {
        ans[S.top().first] = -1;
        S.pop();
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
}
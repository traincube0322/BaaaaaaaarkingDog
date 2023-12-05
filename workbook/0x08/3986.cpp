#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, cnt = 0;
    string str;

    cin >> N;
    while(N--) {
        cin >> str;
        stack<char> S;
        for(auto s : str) {
            if(s == 'A') {
                if(!S.empty()) {
                    if(S.top() == 'A') S.pop();
                    else S.push('A');
                }
                else S.push('A');
            }
            if(s == 'B') {
                if(!S.empty()) {
                    if(S.top() == 'B') S.pop();
                    else S.push('B');
                }
                else S.push('B');
            }
        }
        if(S.empty()) cnt++;
    }
    cout << cnt;
}   
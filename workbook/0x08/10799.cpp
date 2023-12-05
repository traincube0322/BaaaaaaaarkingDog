#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    stack<char> S;
    int cnt = 0, ans = 0;

    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        char s = str[i];
        if(s == '(') {
            S.push('(');
            cnt++;
        }
        if(s == ')') {
            if(str[i-1] == '(') {
                S.pop();
                cnt--;
                ans += cnt;
            }
            else {
                S.pop();
                ans++;
                cnt--;
            }
        }
        
    }
    cout << ans;
}
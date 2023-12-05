#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string str;
    bool TF;

    cin >> N;

    while(N--) {
        TF = true;
        stack<char> S;
        cin >> str;
        for(auto s : str) {
            if(s == '(') S.push('(');
            if(s == ')') {
                if(!S.empty()) S.pop();
                else {
                    TF =false;
                    break;
                }
            }
        }
        if(!S.empty()) TF = false;

        if(TF) cout << "YES\n";
        else cout << "NO\n";
    }
}
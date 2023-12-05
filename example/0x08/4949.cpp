#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    bool YN;

    while(true) {
        
        getline(cin, str);
        if(str == ".") break;

        stack<char> stck;
        YN = true;
        for(auto c : str) {
            if(c == '(' || c == '[') stck.push(c);

            if(c == ')') {
                if(stck.empty() || stck.top() != '('){
                    YN = false;
                    break;
                }
                stck.pop();
            }
            if(c == ']') {
                if(stck.empty() || stck.top() != '['){
                    YN = false;
                    break;
                }
                stck.pop();
            }
        }
        if(!stck.empty()) YN = false;
        if(YN) cout << "yes\n";
        else cout << "no\n";

    }
}
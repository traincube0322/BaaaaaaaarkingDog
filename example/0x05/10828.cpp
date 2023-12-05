#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    stack<int> stck;
    cin >> N;
    string oper;
    int num;

    while(N--) {
        cin >> oper;
        if(oper == "push") {
            cin >> num;
            stck.push(num);
        }
        if(oper == "pop") {
            if(stck.empty()) cout << "-1";
            else {
                cout << stck.top();
                stck.pop();
            }
            cout << "\n";
        }
        if(oper == "size") {
            cout << stck.size() << "\n";
        }
        if(oper == "empty") {
            cout << stck.empty() << "\n";
        }
        if(oper == "top") {
            if(stck.empty()) cout << "-1";
            else cout << stck.top();
            cout << "\n";
        }
    }
}
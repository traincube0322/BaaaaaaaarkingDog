#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    queue<int> Q;
    string oper;
    int num;
    cin >> N;
    
    while(N--) {
        cin >> oper;
        if(oper == "push") {
            cin >> num;
            Q.push(num);
        }
        if(oper == "pop") {
            if(Q.empty()) cout << "-1";
            else {
                cout << Q.front();
                Q.pop();
            }
            cout << "\n";
        }
        if(oper == "size") {
            cout << Q.size();
            cout << "\n";
        }
        if(oper == "empty") {
            cout << Q.empty();
            cout << "\n";
        }
        if(oper == "front") {
            if(Q.empty()) cout << "-1";
            else cout << Q.front();
            cout << "\n";
        }
        if(oper == "back") {
            if(Q.empty()) cout << "-1";
            else cout << Q.back();
            cout << "\n";
        }
        
    }
}
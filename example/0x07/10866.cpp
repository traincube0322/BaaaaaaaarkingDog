#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, num;
    deque<int> D;
    cin >> N;
    string oper;
    
    while(N--) {
        cin >> oper;
        if(oper == "push_front") {
            cin >> num;
            D.push_front(num);
            continue;
        }
        if(oper == "push_back") {
            cin >> num;
            D.push_back(num);
            continue;
        }
        if(oper == "pop_front") {
            if(D.empty()) cout << "-1";
            else {
                cout << D.front();
                D.pop_front();
            }
        }
        if(oper == "pop_back") {
            if(D.empty()) cout << "-1";
            else {
                cout << D.back();
                D.pop_back();
            }
        }
        if(oper == "size") {
            cout << D.size();
        }
        if(oper == "empty") {
            cout << D.empty();
        }
        if(oper == "front") {
            if(D.empty()) cout << "-1";
            else cout << D.front();
        }
        if(oper == "back") {
            if(D.empty()) cout << "-1";
            else cout << D.back();
        }
        cout << "\n";

    }
}
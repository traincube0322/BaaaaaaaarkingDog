#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    list<char> pwd;
    auto cursor = pwd.begin();
    string input;
    cin >> N;
    while(N--) {
        pwd.clear();
        cursor = pwd.begin();
        cin >> input;
        for(auto i : input) {

            if(i == '<'){
                if(cursor != pwd.begin()) cursor--;
            }
            else if(i == '>'){
                if(cursor != pwd.end()) cursor++;
            }
            else if(i == '-') {
                if(cursor != pwd.begin()) cursor = pwd.erase(--cursor);
            }
            else pwd.insert(cursor, i);
        }
        for(auto iter = pwd.begin(); iter != pwd.end(); iter++){
            cout << *iter;
        }
        cout << '\n';
    }
}
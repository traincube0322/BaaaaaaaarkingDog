#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    int M;
    char c;
    list<char> str;
    auto cursor = str.begin();

    cin >> N;
    cin >> M;

    for(auto s : N) {
        str.push_back(s);
    }
    cursor = str.end();

    while(M--) {
        cin >> c;
        if(c == 'L') {
            if(cursor == str.begin()) continue;
            cursor--;
        }
        if(c == 'D') {
            if(cursor == str.end()) continue;
            cursor++;
        }
        if(c == 'B') {
            if(cursor == str.begin()) continue;
            cursor = str.erase(--cursor);
        }
        if(c == 'P') {
            cin >> c;
            str.insert(cursor, c);
        }
    }

    for(auto iter = str.begin(); iter != str.end(); iter++){
        cout << *iter;
    }

}
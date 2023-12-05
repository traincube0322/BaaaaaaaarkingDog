#include <bits/stdc++.h>
using namespace std;

int str[27];


int main() {
    int N;
    cin >> N;
    string str1, str2;
    bool poss;

    while(N--) {
        fill_n(str, 27, 0);
        poss = true;
        cin >> str1 >> str2;
        for(auto c : str1) {
            str[c-'a']++;
        }
        for(auto c : str2) {
            str[c-'a']--;
        }
        for(auto i : str) {
            if(i != 0) {
                poss = false;
            }
        }
        if(poss) cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";

    }
}
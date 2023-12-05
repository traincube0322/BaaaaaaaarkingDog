#include <bits/stdc++.h>
using namespace std;

int num[27];

int main() {
    int total = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for(auto s : str1) {
        num[s-'a']++;
    }
    for(auto s : str2) {
        num[s-'a']--;
    }
    for(auto i : num) {
        total += abs(i);
    }
    cout << total;
}
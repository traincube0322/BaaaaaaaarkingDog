    #include <bits/stdc++.h>
    using namespace std;

    int atoz[26];

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        string str;
        cin >> str;
        for(int i = 0; i < str.length(); i++) {
            atoz[str[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            cout << atoz[i] << " ";
        }
    }
#include <iostream>
#include <string>
using namespace std;

int a[26];

int main() {
    string str;
    cin >> str;

    for(int i = 0; str[i] != '\0'; i++) {
        a[(char)str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        cout << a[i] << " ";
    }
}
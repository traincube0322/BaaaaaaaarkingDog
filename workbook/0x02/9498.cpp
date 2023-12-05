#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n / 10 >= 9) cout << 'A';
    else if (n/10 == 8) cout << 'B';
    else if (n/10 == 7) cout << 'C';
    else if (n/10 == 6) cout << 'D';
    else cout << 'F';
}
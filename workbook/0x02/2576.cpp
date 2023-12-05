#include <bits/stdc++.h>
using namespace std;

int main() {
    int min =100, sum = 0;
    int n;
    for(int i = 0; i < 7; i++) {
        cin >> n;
        if(n % 2 != 0) {
            sum += n;
            if(n < min) min = n;
        }
        
    }
    if(sum == 0) {
        cout << -1;
        return 0;
    }
    cout << sum << '\n';
    cout << min << '\n';
}
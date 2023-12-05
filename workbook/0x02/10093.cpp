#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B;
    if(A > B) {
        C = B;
        B = A;
        A = C;
    }
    if(A == B) {
        cout << 0;
        return 0;
        
    }
    cout << B - A - 1 << '\n';
    for(long long i = A + 1; i < B; i++) {
        cout << i << ' ';
    }
}
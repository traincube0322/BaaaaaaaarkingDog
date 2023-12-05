#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m) {
    if(b == 1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    if(b%2 == 0) return val;
    return val * a % m;
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    cout << POW(A, B, C);
}
#include <bits/stdc++.h>
using namespace std;

int Z(int n, int r, int c) {
    if(n == 0) return 0;

    int half = 1<<(n-1);
    // 구역 1
    if (r < half && c < half) {
        return Z(n-1, r, c);
    }
    // 구역 2
    else if(r < half && c >= half) {
        return half * half + Z(n-1, r, c-half);
    }
    // 구역3
    else if(r >= half && c < half) {
        return half * half * 2 + Z(n-1, r-half, c);
    }
    // 구역 4
    else return half * half * 3 + Z(n-1, r-half, c-half);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c);
}
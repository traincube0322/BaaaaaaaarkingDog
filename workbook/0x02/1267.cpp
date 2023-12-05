#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y = 0, M = 0;
    int N;
    int time;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> time;
        Y += (time / 30 + 1) * 10;
        M += (time / 60 + 1) * 15;
    }
    if (Y == M) {
        cout << "Y M " << Y;
    }

    else cout << (Y < M ? "Y " : "M ") << (Y < M ? Y : M);
}
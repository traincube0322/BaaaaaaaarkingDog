#include <bits/stdc++.h>
using namespace std;

// 원판 n개를 a기둥에서 b기둥으로 옮김.
void hanoi(int n, int a, int b) {
    if(n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    hanoi(n-1, a, 6-a-b);
    cout << a << " " << b << "\n";
    hanoi(n-1, 6-a-b, b);
    
}

int main() {
    int N;
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    hanoi(N, 1, 3);
}
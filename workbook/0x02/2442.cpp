#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = N-i; j>0; j--) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
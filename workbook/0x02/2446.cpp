#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 1; i <= 2*N - 1; i++) {
        if(i <= N) {
            for(int j = 1; j < i; j++) {
                cout << " ";
            }
            for(int j = 1; j <= 2*(N-i+1)-1; j++) {
                cout << "*";
            }
            cout << "\n";
        }
        else{
            for(int j = 1; j < 2*N-i; j++) {
                cout << " ";
            }
            for(int j = 1; j <=  2*(i-N)+1; j++) {
                cout << "*";
            }
            cout << "\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

void star(int x, int y, int n) {
    if(n == 1) {
        if(x % 3 == 1 && y % 3 == 1) cout << " ";
        else cout << "*";
        return;
    }
    int z = n/3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            star(x + i * z, y + j * z, z);
        }
        cout << "\n";
    }
    

}

int main() {
    int N;
    cin >> N;

    star(0,0,N);
}
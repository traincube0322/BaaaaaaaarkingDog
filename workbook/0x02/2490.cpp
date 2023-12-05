#include <bits/stdc++.h>
using namespace std;

int arr[2];
int main() {
    int n, T = 3;
    while(T--) {
        arr[0] = 0;
        arr[1] = 0;
        for(int i = 0; i < 4; i++) {
            cin >> n;
            arr[n]++;
        }
        switch (arr[0])
        {
        case 1:
            cout << 'A' << '\n';
            break;
        case 2:
            cout << 'B' << '\n';
            break;
        case 3:
            cout << 'C' << '\n';
            break;
        case 4:
            cout << 'D' << '\n';
            break;
        
        default:
            cout << 'E' <<'\n';
            break;
        }
    }
}
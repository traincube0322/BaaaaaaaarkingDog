#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    int arr[20];
    for(int i = 0; i < 20; i++) {
        arr[i] = i+1;
    }

    for(int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverse(arr+a-1, arr+b);
    }

    for(int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
}

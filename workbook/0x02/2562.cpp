#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    int max = 0, maxIndex;
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        if(max < arr[i]) {
            max = arr[i];
            maxIndex = i + 1;
        }
    }
    cout << max << '\n';
    cout << maxIndex;
}
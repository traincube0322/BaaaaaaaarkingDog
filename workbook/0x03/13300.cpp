#include <bits/stdc++.h>
using namespace std;

int arr[2][7] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K, S, Y;
    int num = 0;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> S >> Y;
        arr[S][Y]++;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= 6; j++) {
            if(arr[i][j] == 0) continue;
            num += arr[i][j] / K;
            if(arr[i][j] % K) num++;
        }
    }

    cout << num;

}
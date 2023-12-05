#include <bits/stdc++.h>
using namespace std;

int freq[2000001];
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x, num, cnt = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr[i] = num;
        freq[num]++;
    }
    cin >> x;

    for(int i= 0; i < N; i++) {
        if(x-arr[i] > 0 && freq[x - arr[i]]) cnt++;
    }
    cnt /= 2;
    cout << cnt;
}
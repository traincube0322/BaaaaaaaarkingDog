#include <bits/stdc++.h>
using namespace std;
#define HASH 100
int arr[201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num, v;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr[num+HASH]++;
    }
    cin >> v;

    cout << arr[v+HASH];
}
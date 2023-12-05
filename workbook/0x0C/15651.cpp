#include <bits/stdc++.h>
using namespace std;

int n, m;
// 숫자들을 담을 배열.
int arr[8];
bool isused[7][10];

// k번째 수 작성.
void NM(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isused[k][i]) {
            arr[k] = i;
            isused[k][i] = 1;
            NM(k+1);
            isused[k][i] = 0;
        }

    }
}

int main() {
    cin >> n >> m;
    NM(0);
}
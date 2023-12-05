#include <bits/stdc++.h>
using namespace std;


int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, num;
    cin >> A >> B>> C;
    num = A * B * C;
    while(num) {
        arr[num%10]++;
        num /= 10;
    }
    for(int i = 0; i <= 9; i++) {
        cout << arr[i] << "\n";
    }

}
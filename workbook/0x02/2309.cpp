#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int num[9];
    for(int i = 0; i < 9; i++){
        cin >> num[i];
        sum += num[i];
    }
    sort(num, num+9);
    int idx1, idx2;
    for(int i = 0; i < 8; i++) {
        for(int j = i+1; j < 9; j++) {
            if((sum - num[i] - num[j]) == 100){
                idx1 = i;
                idx2 = j;
                break;
            }

        }
    }
    for(int i = 0; i < 9; i++) {
        if(i != idx1 && i != idx2) cout << num[i] << '\n';
    }

}
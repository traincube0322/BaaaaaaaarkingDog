#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int n;

// 열에 있는지?
bool isused1[15];
// y=x+n 위에 있는지?
bool isused2[30];
// y = -x + n 위에 있는지?
bool isused3[30];

void queen(int cur) {
    //  cur번 행에 대해서.
    if(cur == n) {
        cnt++;
        return;
    }
    // i는 열을 나타냄.
    for(int i = 0; i < n; i++) {
        if(!isused1[i] && !isused2[cur+i] && !isused3[cur-i+n-1]){
            isused1[i] = 1;
            isused2[cur+i] = 1;
            isused3[cur-i+n-1]= 1;
            queen(cur+1);
            isused1[i] = 0;
            isused2[cur+i] = 0;
            isused3[cur-i+n-1]= 0;
        }
    }

}
int main() {
    cin >> n;
    queen(0);
    cout << cnt;
}
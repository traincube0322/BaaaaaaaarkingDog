#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, num, sum=0;
    stack<int> S;
    cin >> K;

    while(K--) {
        cin >> num;
        if(num!=0) {
            S.push(num);
            sum += num;
        }
        else {
            sum -= S.top();
            S.pop();
        }
    }
    cout << sum;

}
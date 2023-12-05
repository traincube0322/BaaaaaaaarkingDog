#include <bits/stdc++.h>
using namespace std;

// 큐에서 push하고 pop 할 때 현재의 min 값과 pop하는 값을 비교
// 20억짜리 배열은 좀 무리인걱같음. 같은 숫자가 몇개 남았는지 카운트 할 방법 필요함.
// 큐를 두 개 만들어서 같이 회전시키면 됨!!

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L, min = INT_MAX, num;
    queue<int> Q, minQ;

    cin >> N >> L;

    for(int i = 0; i < L; i++) {
        cin >> num;
        if(num < min) min = num;
        Q.push(num);
    }

    for(int i = L; i < N; i++) {
        cin >> num;

    }
    
}

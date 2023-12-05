#include <bits/stdc++.h>
using namespace std;

int main() {
    // index, value
    stack<int> S;
    int N, num, ans = 0;
    cin >> N;
    //  작은애 들어올 때 ans++, top보다 큰 애 들어오면 더 큰 애 만나기 전까지 pop, pop하면서 ans++;
    // 키가 같은 사람이 들어올 떄 골떄림.
    
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(S.empty()) S.push(num);
        else {
            while(!S.empty() && S.top() < num) {
                ans++;
                S.pop();
            }
            if(S.empty()) ans--;
            ans++;
            S.push(num);
        }


        stack<int> S2(S);
        while(!S2.empty()) {
            cout << "STACK : " << S2.top() << "\n";
            S2.pop();
        }

        cout << "==============\n";
    }
    
    
    
    cout << ans;
}   


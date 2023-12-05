#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin >> n;
    stack<int> S;
    stack<int> c;
    string str;
    // 1이 가장 위에있고 n이 가장 아래에 있는 스택 c 초기화.
    for(int i = n; i >= 1 ;i--) {
        c.push(i);
    }
    // S가 빈 경우를 방지하기 위한 젤 밑에 -1값 추가.
    // S.empty() 대신 S.size() == 1인 경우 S가 빈 걸로 간주함.
    S.push(-1);
    while(n--) {
        cin >> num;
        
        // S의 top이 num이 아니라면. (S스택에 추가해야하는 상황.)
        while(num != S.top()) {
            // C스택이 있다면,
            if(!c.empty()) {
                S.push(c.top());
                c.pop();
                str.append("+");
            }
            // 아니면 불능.
            else {
                cout << "NO";
                return 0;
            }
        }
        
        //S가 비어있지 않은 경우.
        if(S.size() != 1) {
            S.pop();
            str.append("-");
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for(auto s : str) {
        cout << s << "\n";
    }
}
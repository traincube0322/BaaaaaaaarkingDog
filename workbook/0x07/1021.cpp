#include <bits/stdc++.h>
using namespace std;

int N, M;
int main() {
    cin >> N >> M;
    deque<int> D;
    int cnt = 0;
    int tmp, idx;
    for(int i = 1; i <= N; i++) {
        D.push_back(i);
    }

    while(M--) {
        cin >> tmp;
        // 반복자의 뺄셈 연산은 두 반복자 사이의 간격을 나타냄.
        // D.begin()이 시작이기 때문에 find()를 통해 찾은 tmp가 저장된 값의 iterator에서 D.begin()을 빼면, tmp의 인덱스가 정수형으로 저장됨.
        idx = find(D.begin(), D.end(), tmp) - D.begin();
        auto it = D.begin();

        while(D.front() != tmp) {
            
            if(idx < D.size() - idx) {
                D.push_back(D.front());
                D.pop_front();
            }
            else {
                D.push_front(D.back());
                D.pop_back();
            }
            cnt++;
        }
        D.pop_front();
    }
    cout << cnt;
    

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> num;
    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        num.push_back(i);
    }
    auto pointer = num.begin();
    cout << "<";
    while(N--) {
        for(int i = 0; i < K-1; i++) {
            pointer++;
            if(pointer == num.end()) pointer = num.begin();
        }
        if(num.size() == 1) break;
        cout << *pointer << ", ";
        pointer = num.erase(pointer);
        if(pointer == num.end()) pointer = num.begin();
    }
    cout << *pointer << ">";
}
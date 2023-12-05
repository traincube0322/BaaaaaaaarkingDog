#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > tower;
    int N, height;

    cin >> N;
    tower.push({100000001, 0});
    for(int i = 1; i <= N; i++) {
        cin >> height;
        while(tower.top().first < height)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({height, i});
    }
}
    


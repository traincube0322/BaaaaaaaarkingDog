#include <bits/stdc++.h>
using namespace std;

int dist[100005];

int main() {
    queue<int> Q;
    int N, K;
    cin >> N >> K;
    fill(dist, dist+100005, -1);
    dist[N] = 0;
    Q.push(N);
    
    while(dist[K] == -1) {
        int cur = Q.front();
        Q.pop();
        for(int next : {cur-1, cur+1 ,2*cur}){
            if(next < 0 || next > 100000) continue;
            if(dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }

    cout << dist[K];
}
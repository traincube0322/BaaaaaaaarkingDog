#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000000

int dist[MAX_SIZE + 1];

int main() {
    int F, S, G, U, D;
    queue<int> Q;
    
    cin >> F >> S >> G >> U >> D;
    fill(dist, dist+F+1, -1);
    Q.push(S);
    dist[S] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        if(cur == G) {
            cout << dist[cur];
            return 0;
        }
        Q.pop();
        
        for(int nxt : {cur + U, cur - D}) {
            if(nxt < 1 || nxt > F ) continue;
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << "use the stairs";

}
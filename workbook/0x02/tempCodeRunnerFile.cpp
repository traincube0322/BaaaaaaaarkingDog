    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;
        cin >> N;
        for(int i = 1; i <= 2*N + 1; i++) {
            // i == N까지 동작.
            if(i <= N) {
                for(int j = 1; j <= N - i; j++){
                    cout << " ";
                }
                for(int j = 1; j <= i*2 - 1; j++){
                    cout << "*";
                }
                cout << "\n";
            }
            else {
                for(int j = 1; j <= i - N;j++) {
                    cout << " ";
                }
                for(int j = 1; j <= 4*N - 2*i -1; j++) {
                    cout << "*";
                }
                cout << "\n";
            }
        }
    }